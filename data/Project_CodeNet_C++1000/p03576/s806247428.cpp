#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (ll i = a; i < b; i++)
#define REP(i,b) FOR(i,0,b)
#define RFOR(i,a,b) for (ll i = a-1; i >= b; i--)
#define RREP(i,a) RFOR(i,a,0)
#define REPALL(i,x) for (ll i = 0; i < x.size(); i++)
#define RREPALL(i,x) for (ll i = x.size()-1; i >= 0; i--)
#define REPITR(itr,x) for (auto itr = (x).begin(); itr != (x).end(); itr++)
#define ALL(x) (x).begin(), (x).end()
#define SORT(x) sort(ALL(x))
#define MIN_ELEMENT(x) min_element(ALL(x))
#define MAX_ELEMENT(x) max_element(ALL(x))
#define COUNT(x,num) count(ALL(x), num)
#define MEMSET(x,val) memset(x, val, sizeof(x))
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define debug(x) cerr<<__LINE__<<": "<<(#x)<<" = "<<(x)<<endl;
void YES(bool flag) {cout<<(flag ? "YES" : "NO")<<endl;}
void Yes(bool flag) {cout<<(flag ? "Yes" : "No")<<endl;}
void yes(bool flag) {cout<<(flag ? "yes" : "no")<<endl;}
#define e1 first
#define e2 second
#define nextline putchar('\n')
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef vector<ll> VLL;
typedef vector<vector<ll>> VVLL;
const long double INF = 1e19;
const ll MOD = 1e9 + 7;
const double pi = 3.141592653589793;

ll n, k;
vector<pair<long double, long double>> v;
vector<long double> x, y;

long double cnt(int x1, int x2, int y1, int y2)
{
    int r = 0;
    REPALL(i,v) {
        if (x[x1] <= v[i].e1 && v[i].e1 <= x[x2] && y[y1] <= v[i].e2 && v[i].e2 <= y[y2]) {
            r++;
        }
    }

    return r >= k ? (x[x2] - x[x1]) * (y[y2] - y[y1]) : INF;
}

int main()
{
    cin>>n>>k;
    x.resize(n); y.resize(n);
    REP(i,n) {
        cin>>x[i]>>y[i];
        v.push_back(make_pair(x[i], y[i]));
    }
    SORT(x); SORT(y);

    long double ans = INF;
    REP(x1,n) {
        FOR(x2,x1+1,n) {
            REP(y1,n) {
                FOR(y2,y1+1,n) {
                    MIN(ans, cnt(x1,x2,y1,y2));
                }
            }
        }
    }

    cout<<fixed << setprecision(0)<<ans<<endl;

    return 0;
}
