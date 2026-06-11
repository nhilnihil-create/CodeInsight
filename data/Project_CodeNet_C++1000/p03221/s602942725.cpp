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
    ll n, m; cin >> n >> m;
    using p = tuple<ll, ll, ll>;
    vector<p> v;
    REP(i, m) {
        ll p, y; cin >> p >> y;
        v.push_back(make_tuple(p, y, i));
    }
    sort(ALL(v));
    map<ll, ll> mc;
    map<ll, string> mp;
    REP(i, m) {
        ll tmp_p = get<0>(v[i]);
        ll tmp_y = get<1>(v[i]);
        ll tmp_i = get<2>(v[i]);
        char s[14];
        sprintf(s, "%06lld%06lld", tmp_p, mc[tmp_p]+1);
        mc[tmp_p]++;
        mp[tmp_i] = s;
    }
    REP(i, m) {
        cout << mp[i] << endl;
    }
    return 0;
}