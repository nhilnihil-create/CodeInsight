#include "bits/stdc++.h"
using namespace std;
 
/** Template Begins **/

#define ll          long long 
#define IOS         ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl        '\n'
 
const int N = 5e6+7;
template<class L, class R> ostream &operator<<(ostream &os, pair<L,R> P) {
  return os << "(" << P.first << "," << P.second << ")";
} 

template<class T> ostream &operator<<(ostream& os, vector<T> V) {
  os << "["; for (auto vv : V) os << vv << ","; return os << "]";
}
 
template<class TH> void _dbg(const char *sdbg, TH h){ cerr << sdbg << '=' << h << endl; }
 
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',') cerr << *sdbg++;
  cerr<<'='<<h<<','; _dbg(sdbg+1, a...);
}
 
#ifdef LOCAL
#define debug(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (__VA_ARGS__)
#define cerr if(0)cout
#endif
/** Template Ends **/
using pii = pair<int, int>;

ll solve(multiset<pii> lf, multiset<pii> rt, int mv)
{
    int cur = 0;
    ll ans = 0;
    for (; rt.size(); mv++)
    {
        debug(mv);
        if (mv & 1)
        {
            pii p = *rt.rbegin();    rt.erase(rt.find(p));   lf.erase(lf.find({p.second, p.first}));
            debug(p, cur);
            ans += max(0, p.first - cur);
            cur = max(cur, p.first);
        }
        else
        {
            pii p = *lf.begin();    lf.erase(lf.find(p));   rt.erase(rt.find({p.second, p.first}));
            debug(p, cur);
            ans += max(0, cur - p.first);
            cur = min(cur, p.first);
        }
    }
    ans += abs(cur);
    debug(ans);
    return ans;
}

signed main() 
{ 
    IOS;
    int n;  cin >> n;
    multiset<pii> rt, lf;

    for (int i = 0; i < n; i++)
    {
        int x, y;   cin >> x >> y;
        rt.insert({x, y});
        lf.insert({y, x});
    }
    debug(lf.size());
    cout << max(solve(lf, rt, 0), solve(lf, rt, 1)) << endl;

    return 0;
}