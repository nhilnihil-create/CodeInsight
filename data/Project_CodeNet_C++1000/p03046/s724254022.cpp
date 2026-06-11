#include<bits/stdc++.h>
using namespace std;
//#pragma region atcoder
/*#include <atcoder/dsu>
using namespace atcoder;*/
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

const ll mod = 1000000007;
const int inf = 1001001001;
const ll INF = 1001001001001001001;

template<class T>bool chmax(T &a, const T b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T b) { if (b<a) { a=b; return 1; } return 0; }
ll modpow(ll a, ll p){ll ret = 1; while(p){if(p & 1){ret = ret * a % mod;} a = a * a % mod; p >>= 1;} return ret;}

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

/*-----------------------------------------------------------------------------------------------------*/
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int m, k; cin >> m >> k;
	if(k >= pow(2, m)) cout << -1 << endl;
	else if(m == 1){
		if(k == 0) cout << "1 1 0 0" << endl;
		else cout << -1 << endl;
	}
	else{
		vi b(1 << m);
		rep(i, 1<<m) b[i] = i;
		vi c = b;
		reverse(all(c));
		rep(i,sz(b)){
			if(i == k) continue;
			cout << i << " ";
		}
		cout << k << " ";
		rep(i,sz(c)){
			if(c[i] == k) continue;
			cout << c[i] << " ";
		}
		cout << k << endl;
	}
}