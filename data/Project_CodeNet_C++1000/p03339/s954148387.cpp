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
inline void IN(void){return;}
template <typename First, typename... Rest>
void IN(First& first, Rest&... rest){cin >> first;IN(rest...);return;}
template<class T>bool chmax(T &a, const T &b) {if(a<b){a=b; return 1;} return 0;}
template<class T>bool chmin(T &a, const T &b) {if(b<a){a=b; return 1;} return 0;}
const ll INF = 1LL << 60;
const int dx[8] = {1,0,-1,0,1,1,-1,-1}; const int dy[8] = {0,1,0,-1,1,1,-1,-1};

int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    ll n;
    string s;
    cin >> n >> s;
    vl dir(n);
    rep(i,n){
        // 左は0、右は1
        if(s[i]=='E') dir[i]=1;
        else dir[i]=0;
    }

    vl s0(n+1,0),s1(n+1,0);
    rep(i,n){
        s0[i+1] = s0[i] + 1-dir[i];
        s1[i+1] = s1[i] + dir[i];
    }

    ll ans = INF;
    chmin(ans,s1[n]-s1[1]);
    chmin(ans,s0[n-1]);
    rep(i,1,n-1){
        chmin(ans,s0[i]+s1[n]-s1[i+1]);
    }
    cout << ans << endl;
}