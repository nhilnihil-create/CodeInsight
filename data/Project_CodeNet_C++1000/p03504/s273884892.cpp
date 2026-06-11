#include<bits/stdc++.h>
using namespace std;
#pragma region atcoder
//using mint = modint998244353;
//These are for segment tree
/*int op(int a, int b){return max(a, b);}
int e(){return -1;}
bool f(int v){ return v < target;}
*/
#pragma endregion
#pragma region macros
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vl = vector<ll>;
using vb = vector<bool>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rrep(i, n) for(int i = n - 1; i >= 0; i--)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((int)(x).size())
#pragma endregion
#pragma region debug for var, v, vv
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e){std::cout << e << std::endl;}
template<typename T> void view(const std::vector<T>& v){for(const auto& e : v){ std::cout << e << " "; } std::cout << std::endl;}
template<typename T> void view(const std::vector<std::vector<T> >& vv){cout << endl;int cnt = 0;for(const auto& v : vv){cout << cnt << "th : "; view(v); cnt++;} cout << endl;}
#pragma endregion
const ll mod = 998244353;
const int inf = 1001001001;
const ll INF = 1001001001001001001;
const int MAX = 2000005;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

template<class T>bool chmax(T &a, const T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T b) { if (b<a) { a=b; return 1; } return 0; }
ll modpow(ll a, ll p){ll ret = 1; while(p){if(p & 1){ret = ret * a % mod;} a = a * a % mod; p >>= 1;} return ret;}

/*--------------------------------------------------------------------------------------------------------------------------------*/

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
    int N, C; cin >> N >> C;
    vi s(N), t(N), c(N);
    vvi broadcast(C+1, vi(100002, 0));
    rep(i,N){
        cin >> s[i] >> t[i] >> c[i];
        s[i]--;
        broadcast[c[i]][s[i]]++;
        broadcast[c[i]][t[i]]--;
    }
    for(int i = 1; i <= C; i++){
        rep(j, 100001) broadcast[i][j + 1] += broadcast[i][j];
        //for(int j = 1; j < 100; j++) cout << broadcast[i][j];
        //cout << endl;
    }
    int ans = 0;
    rep(i, 100002){
        int tmp = 0;
        for(int j = 1; j <= C; j++){
            tmp += (broadcast[j][i] != 0 ? 1 : 0);
        }
        //if(tmp == 3) cout << i << endl;
        ans = max(tmp, ans);
    }
    cout << ans << endl;
}