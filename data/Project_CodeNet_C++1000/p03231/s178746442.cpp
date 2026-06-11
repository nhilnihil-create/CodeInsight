#include<algorithm>
#include<bitset>
#include<cmath>
#include<complex>
#include<deque>
#include<functional>
#include<iomanip>
#include<iostream>
#include<iterator>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
#define ALL(x) (x).begin(),(x).end()
#define SIZE(x) ((ll)(x).size())
#define MAX(x) *max_element(ALL(x))
#define MIN(x) *min_element(ALL(x))
#define D()
#define INF 1000000000000
#define MOD 10000007
#define MAXR 100000
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define INITA(a,i,j,v) for(ll k=i;k<=j;k++){a[k]=v;}

ll gcd(ll a, ll b) {
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a % b);
    }
}

int main() {
    ll n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    ll len = n * m / gcd(n, m);
    if (s[0] != t[0]) {
        cout << -1 << endl;
        return 0;
    }

    if (n >= m) {
        FOR(i, 1, n - 1) {
            if (((i * len / n) % (len / m) == 0) && (s[i] != t[i * m / n])) {
                cout << - 1 << endl;
                return 0;
            }
        }
    } else {
        FOR(i, 1, m - 1) {
            if (((i * len / m) % (len / n) == 0) && (t[i] != s[i * n / m])) {
                cout << - 1 << endl;
                return 0;
            }
        }
    }
    cout << len << endl;
    return 0;
}