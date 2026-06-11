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

int main() {
    ll n; cin >> n;
    map<char, ll> m;
    m['M'] = 0;
    m['A'] = 0;
    m['R'] = 0;
    m['C'] = 0;
    m['H'] = 0;
    REP(i, n) {
        string s;
        cin >> s;
        if ((s[0] == 'M') || (s[0] == 'A') || (s[0] == 'R') || (s[0] == 'C') || (s[0] == 'H')) {
            m[s[0]]++;
        }
    }
    string march = "MARCH";
    ll res = 0;
    FOR(i, 0, 4) {
        FOR(j, i+1, 4) {
            FOR(k, j+1, 4) {
                res += m[march[i]] * m[march[j]] * m[march[k]];
            }
        }
    }
    cout << res << endl;
    return 0;
}