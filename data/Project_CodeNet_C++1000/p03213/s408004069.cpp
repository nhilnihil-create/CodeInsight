#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef pair <ll,ll> P;
#define REP(i, n) for(int i = 0; i < (int)(n); i++)
#define REPR(i, n) for(int i = n-1; i >= 0; i--)
#define FOR(i, n, m) for(int i = n; i < (int)(m); i++)
#define PRINT(x) cout << x << endl
#define ALL(v) v.begin(), v.end()
#define INF (ll)1e18

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll MOD = 1000000007;

int main()
{
    ll N;
    cin >> N;
    vector<int> x(N + 1);
    FOR(n, 2, N+1) {
        int num = n; // 素因数分解する変数num

        for (int i = 2; i <= n; i++) {
            while (num%i == 0) { // 素数で割り切れなくなるまで割っていく
                x[i]++;
                num /= i;
            }
        }
    }
    ll cnt3 = 0;
    ll cnt5 = 0;
    ll cnt15 = 0;
    ll cnt25 = 0;
    ll cnt75 = 0;
    REP(i, N+1)
    {
        if (x[i]+1 >= 3) cnt3++;
        if (x[i]+1 >= 5) cnt5++;
        if (x[i]+1 >= 15) cnt15++;
        if (x[i]+1 >= 25) cnt25++;
        if (x[i]+1 >= 75) cnt75++;
    }

    ll ans = 0;
    ans += cnt75;
    ans += cnt25 * max(0LL, (cnt3-1));
    ans += cnt15 * max(0LL, cnt5-1);
    ans += (cnt5 * (cnt5-1))/2 * max(0LL, (cnt3-2));
    PRINT(ans);
    return 0;
}
