#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n-1; i >= 0; i--)
#define FOR(i, n, m) for(int i = n; i < (int)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll MOD = 1000000007;


int main()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    REP(i, N) cin >> A[i];
    vector<ll> B(N);
    REP(i, N) cin >> B[i];
    vector<ll> C(N);
    REP(i, N) C[i] = A[i] - B[i];
    sort(ALL(C));
    ll ans = 0;
    ll cnt = 0;
    REP(i, N) {
        if (C[i] < 0){
            cnt++;
            ans += C[i];
        }
    }
    if (ans == 0) {
        PRINT(0);
        return 0;
    }
    REPR(i, N) {
        if (C[i] > 0) {
            cnt++;
            ans += C[i];
            if (ans >= 0) break;
        } else {
            PRINT(-1);
            return 0;
        }
    }
    PRINT(cnt);
    return 0;
}
