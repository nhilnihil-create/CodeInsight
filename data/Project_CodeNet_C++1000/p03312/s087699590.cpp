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

ll vec[200001];
int n;

int solve(int l, int r) {
    int le = l, ri = r - 1, mid;
    ll nn = vec[r] - vec[l - 1];

    while (le <= ri) {
        mid = (le + ri) / 2;
        ll sum = vec[mid] - vec[l - 1];
        if (sum < nn / 2) le = mid + 1;
        else ri = mid - 1;
    }

    return max(l, ri);
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &vec[i]);
        vec[i] += vec[i - 1];
    }

    // 왼쪽구간 끝
    ll ans = 1e18;
    for (int i = 2; i <= n - 2; i++) {
        int le = solve(1, i);
        int ri = solve(i + 1, n);

        for (int j = 0; j < 2 - (le+1 == i); j++) {
            for (int k = 0; k < 2 - (ri+1 == n); k++) {
                ll miv = 1e18, mav = 0;
                if (j == 0) {
                    mav = max(mav, vec[le]);
                    miv = min(miv, vec[le]);
                    mav = max(mav, vec[i] - vec[le]);
                    miv = min(miv, vec[i] - vec[le]);
                }
                else {
                    mav = max(mav, vec[le + 1]);
                    miv = min(miv, vec[le + 1]);
                    mav = max(mav, vec[i] - vec[le + 1]);
                    miv = min(miv, vec[i] - vec[le + 1]);
                }

                if (k == 0) {
                    mav = max(mav, vec[ri] - vec[i]);
                    miv = min(miv, vec[ri] - vec[i]);
                    mav = max(mav, vec[n] - vec[ri]);
                    miv = min(miv, vec[n] - vec[ri]);
                }
                else {
                    mav = max(mav, vec[ri + 1] - vec[i]);
                    miv = min(miv, vec[ri + 1] - vec[i]);
                    mav = max(mav, vec[n] - vec[ri + 1]);
                    miv = min(miv, vec[n] - vec[ri + 1]);
                }
                ans = min(ans, mav - miv);
            }
        }
    }

    printf("%lld", ans);
}