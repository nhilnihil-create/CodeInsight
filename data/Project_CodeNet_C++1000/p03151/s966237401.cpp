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
    ll a[100001]; INITA(a, 0, 100000, 0);
    ll b[100001]; INITA(b, 0, 100000, 0);

    ll a_tot = 0;
    ll b_tot = 0;
    REP(i, n) { cin >> a[i]; a_tot += a[i]; }
    REP(i, n) { cin >> b[i]; b_tot += b[i]; }

    if (a_tot < b_tot) {
        cout << -1 << endl;
    } else {
        // a - bの差分を取得する (plus, minusにわける)
        vector<ll> plus;
        ll minus_tot = 0;
        ll res = 0;
        REP(i, n) {
            ll diff = a[i] - b[i];
            if (diff < 0) {
                minus_tot -= diff;
                res++;
            } else if (diff > 0) {
                plus.push_back(diff);
            }
        }
        sort(ALL(plus));
        while (minus_tot > 0) {
            ll p = plus[plus.size()-1];
            plus.pop_back();
            res++;
            minus_tot -= p;
        }
        cout << res << endl;
    }

    return 0;
}
