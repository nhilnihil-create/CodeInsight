#include <bits/stdc++.h>
//#define int long long

using namespace std;
using LL = long long;
using P = pair<int, int>;

#define FOR(i, a, n) for(int i = (int)(a); i < (int)(n); ++i)
#define REP(i, n) FOR(i, 0, n)

#define pb(a) push_back(a)
#define all(x) (x).begin(),(x).end()

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}
template<typename T,typename... Ts>
auto make_v(size_t a, Ts... ts) {return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...)); }

template<typename T,typename V>
typename enable_if<is_class<T>::value == 0>::type
fill_v(T &t, const V &v){ t = v; }

template<typename T,typename V>
typename enable_if<is_class<T>::value != 0>::type
fill_v(T &t, const V &v){ for(auto &e : t) fill_v(e, v); }

const int INF = (int)1e9;
const LL INFL = (LL)1e18;
const int MOD = 1e9 + 7;

signed main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<char> t(q), d(q);
    REP(i, q) cin >> t[i] >> d[i];

    int ok = -1, ng = n;
    while(abs(ok - ng) > 1)
    {
        int mid = (ok + ng) / 2;
        int cur = mid;
        REP(i, q)
        {
            if(s[cur] == t[i]) cur += (d[i] == 'L' ? -1 : 1);
            if(cur < 0 || cur >= n) break;
        }
        if(cur < 0) ok = mid;
        else ng = mid;
    }
    int l = ok;

    ok = n, ng = -1;
    while(abs(ok - ng) > 1)
    {
        int mid = (ok + ng) / 2;
        int cur = mid;
        REP(i, q)
        {
            if(s[cur] == t[i]) cur += (d[i] == 'L' ? -1 : 1);
            if(cur < 0 || cur >= n) break;
        }
        if(cur >= n) ok = mid;
        else ng = mid;
    }
    int r = ok;

    cout << r - l - 1 << endl;
}