#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
const ll MOD = (ll)1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

ll fac[1], inv[1];
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll mp(ll a,ll b){ll ret=1;while(b){if(b&1)ret=ret*a%MOD;a=a*a%MOD;b>>=1;}return ret;}
ll cmb(ll r, ll c) {return fac[r] * inv[c] % MOD * inv[r - c] % MOD;}

priority_queue<int, vector<int>, greater<int>> pq;
vector<int> v;

int n;
int vec[1 << 18];
pii dp[1 << 18][2];

int main() {
    memset(dp, -1, sizeof(dp));
    scanf("%d", &n);

    // 0인덱스고,
    // k에 대해 그렇다는 건..
    // 사실 이번에 추가되는 쌍만 누적시켜주면 되는건데..
    // or값이 k인 어떤 비트들 중 두 인덱스 값의 합이 가장 큰거.

    // 1. 모든 쌍 비교 가능?
    // 2. OR값이 정확히 K인 쌍들의 max를 빠르게 구하자.
    // 최상위 비트? 그 비트외에 다른 것이 안켜져 있는 subset들의 max?

    // 나보다 하나 더 켜져있는 것들로 보낸다.
    // 잘못하면 중복됨.
    // 차라리 상위비트의 max를 구하면?
    // 나도 그 하위비트들은 다 봤던거고..
    // 그렇게하면 distinct 해지나?
    // max 두개까지..
    // 그게 어떤 쌍이든 상관없다..
    // pair<>의 max를 저장해서 second까지 함.

    int mav = 0;
    for (int i = 0; i < (1<<n); i++) {
        scanf("%d", &vec[i]);

        pii now = {vec[i], i};
        if (dp[i][1] < now) {
            swap(dp[i][1], now);
            if (dp[i][0] < dp[i][1])
                swap(dp[i][0], dp[i][1]);
        }

        for (int j = 0; j < n; j++) {
            int bit = i | 1 << j;
            if (i == bit) continue;

            now = dp[i][0];
            if (dp[bit][1].second == now.second || dp[bit][0].second == now.second);
            else {
                if (dp[bit][1] < now) {
                    swap(dp[bit][1], now);
                    if (dp[bit][0] < dp[bit][1])
                        swap(dp[bit][0], dp[bit][1]);
                }
            }

            now = dp[i][1];
            if (dp[bit][1].second == now.second || dp[bit][0].second == now.second);
            else {
                if (dp[bit][1] < now) {
                    swap(dp[bit][1], now);
                    if (dp[bit][0] < dp[bit][1])
                        swap(dp[bit][0], dp[bit][1]);
                }
            }
        }

        mav = max(mav, dp[i][0].first + dp[i][1].first);
        if (i) printf("%d\n", mav);
    }
}