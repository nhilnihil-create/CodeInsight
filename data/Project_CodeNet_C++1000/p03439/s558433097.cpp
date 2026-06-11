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
#define PI 3.14159265358979

ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

ll MOD = 1000000007;

int main()
{
    ll N;
    cin >> N;
    string lstr;
    cout << 0 << endl;
    cin >> lstr;
    if (lstr == "Vacant") {
        return 0;
    }
    ll l = 0;
    ll r = N;
    while(r - l >= 1){
        ll m = l + (r - l) / 2;
        cout << m << endl;
        string tmp;
        cin >> tmp;
        if (tmp == "Vacant") {
            return 0;
        }
        if ((m-l) % 2 == 0) {
            if (tmp == lstr) {
                l = m;
            } else {
                r = m;
            }
        } else {
            if (tmp != lstr) {
                l = m;
                lstr = tmp;
            } else {
                r = m;
            }
        }
    }
    return 0;
}
