#include <bits/stdc++.h>
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define rrep(i,n) for (int i=(n-1);i >= 0;i--)
#define all(v) v.begin(),v.end()
#define sz(v) (int)((v).size())
#define MAX(v) *max_element(all(v))
#define MIN(v) *min_element(all(v))
using namespace std; using ll = long long; using P = pair<int,int>;
using vl = vector<ll>; using vvl = vector<vl>;
void debug_out() { cout << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cout << H << " ";
    debug_out(T...);
}
#ifdef _DEBUG
#define debug(...) debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif
template <typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec) {
    for (std::size_t i = 0; i < vec.size(); i++)os << vec[i] << (i + 1 == vec.size() ? "" : " ");
    return os;
}
inline void IN(void){return;}
template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){cin >> first;IN(rest...);return;}
template<class T>bool chmax(T &a, const T &b) {if(a<b){a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if(b<a){a=b; return 1;} return 0;}
const ll INF = 1LL << 60;
const ll mod = 1000000007;
const int dx[8] = {1,0,-1,0,1,1,-1,-1}; const int dy[8] = {0,1,0,-1,1,1,-1,-1};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    ll r,g,b,n;
    IN(r,g,b,n);
    ll ans = 0;
    for(int i = 0;i*r <= n;i++){
        for(int j = 0;j*g<=n;j++){
            int v = n-i*r-j*g;
            if(v>=0 && v%b==0) ans++;
        }
    }
    cout << ans << endl;
}