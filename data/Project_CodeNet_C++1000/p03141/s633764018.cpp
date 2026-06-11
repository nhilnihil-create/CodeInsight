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
    vector<P> v(N);
    vector<P> C(N);
    REP(i, N) {
        ll A, B;
        cin >> A >> B;
        v[i] = P(A, B);
        C[i] = P(A+B, i);
    }
    sort(ALL(C));
    ll a = 0;
    ll b = 0;
    REP(i, N) {
        if (i % 2 == 0) {
            a += v[C[N-1-i].second].first;
        } else {
            b += v[C[N-1-i].second].second;
        }
    }
    PRINT(a - b);
    return 0;
}
