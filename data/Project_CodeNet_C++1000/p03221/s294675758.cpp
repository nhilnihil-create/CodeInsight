#pragma region RegionDefs
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define reps(i,l,r) for(int i=(l),i##_len=(r);i<i##_len;++i)
#define repr(i,l,r) for(int i=(r)-1,i##_left=(l);i>=i##_left;--i)
#define all(x) begin(x),end(x)
using namespace std;
typedef long long ll;
const ll INF = 1e9;
template<class T=ll> using V = vector<T>;
template<class T=ll> using PQ = priority_queue<T>;
template<class T=ll> using PQG = priority_queue<T, V<T>, greater<T>>;
const ll MOD = 1000000007LL;
void in() {}
template<class Head, class... Tail>
void in(Head&& head, Tail&&... tail) { cin >> head; in(move(tail)...); }
#define IN(...) ll __VA_ARGS__; in(__VA_ARGS__)
#define TIN(T, ...) T __VA_ARGS__; in(__VA_ARGS__)
#define VIN(T, v, n) V<T> v(n); for(auto& _elem:v)cin>>_elem
#define VIND(T, v, n) V<T> v(n); for(auto& _elem:v)cin>>_elem,--_elem
#define OUT(x) cout << x;
#define OUTL(x) cout << x << endl;
template<class T>bool chmax(T &a, const T &b) {if (a<b) {a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if (a>b) {a=b; return 1;} return 0;}
template<class T>
string join(vector<T>& v, string delim="") { ostringstream os; rep(i,v.size())i?os<<delim<<v[i]:os<<v[0]; return os.str(); }
#pragma endregion RegionDefs

template<class T>
vector<T> compress(vector<T>& v) {
    vector<T> v2 = v;
    sort(v2.begin(), v2.end());
    v2.erase(unique(v2.begin(), v2.end()), v2.end());
    rep(i, v.size())
        v[i] = lower_bound(v2.begin(), v2.end(), v[i]) - v2.begin();
    return v2;
}

void solve()
{
    IN(n, m);
    V<ll> p(m), y(m);
    rep(i, m) cin >> p[i] >> y[i], --p[i];
    V<V<ll>> v(n);
    rep(i, m) v[p[i]].push_back(y[i]);
    rep(i, n) sort(all(v[i]));
    rep(i, m) {
        string q = to_string(p[i] + 1);
        string c = to_string(lower_bound(all(v[p[i]]), y[i]) - v[p[i]].begin() + 1);
        rep(j, 6-q.size()) cout << "0";
        cout << q;
        rep(j, 6-c.size()) cout << "0";
        cout << c << endl;
    }
}

int main()
{
    cin.tie(0); cout.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(numeric_limits<double>::max_digits10);

    solve();

    return 0;
}