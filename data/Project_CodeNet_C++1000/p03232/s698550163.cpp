#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define dbg(...) do{cerr<<__LINE__<<": ";dbgprint(#__VA_ARGS__, __VA_ARGS__);}while(0);

using namespace std;

namespace std{template<class S,class T>struct hash<pair<S,T>>{size_t operator()(const pair<S,T>&p)const{return ((size_t)1e9+7)*hash<S>()(p.first)+hash<T>()(p.second);}};template<class T>struct hash<vector<T>>{size_t operator()(const vector<T> &v)const{size_t h=0;for(auto i : v)h=h*((size_t)1e9+7)+hash<T>()(i)+1;return h;}};}
template<class T>ostream& operator<<(ostream &os, const vector<T> &v){os<<"[ ";rep(i,v.size())os<<v[i]<<(i==v.size()-1?" ]":", ");return os;}template<class T>ostream& operator<<(ostream &os,const set<T> &v){os<<"{ "; for(const auto &i:v)os<<i<<", ";return os<<"}";}
template<class T,class U>ostream& operator<<(ostream &os,const map<T,U> &v){os<<"{";for(const auto &i:v)os<<" "<<i.first<<": "<<i.second<<",";return os<<"}";}template<class T,class U>ostream& operator<<(ostream &os,const pair<T,U> &p){return os<<"("<<p.first<<", "<<p.second<<")";}
void dbgprint(const string &fmt){cerr<<endl;}template<class H,class... T>void dbgprint(const string &fmt,const H &h,const T&... r){cerr<<fmt.substr(0,fmt.find(","))<<"= "<<h<<" ";dbgprint(fmt.substr(fmt.find(",")+1),r...);}
typedef long long ll;typedef vector<int> vi;typedef pair<int,int> pi;const int inf = (int)1e9;const double INF = 1e12, EPS = 1e-9;

const int mod = 1e9 + 7;
const int MX = 110000;
ll inv[MX], f[MX], invf[MX];
void calc(){
	inv[0] = inv[1] = f[0] = f[1] = invf[0] = invf[1] = 1;
	for (int i = 2; i < MX; i++){
		inv[i] = mod - mod / i * inv[mod % i] % mod;
		f[i] = f[i - 1] * i % mod;
		invf[i] = invf[i - 1] * inv[i] % mod;
	}
}

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	calc();
	int n; cin >> n;
	vi v(n); rep(i, n) cin >> v[i];
	vector<ll> s(n + 1), lensum(n + 1);
	rep(i, n) s[i + 1] = (s[i] + v[i]) % mod;
	
	for(int i = 1, l = 0, r = n; 2 * i <= n + 1; i++){
		lensum[i] = (lensum[i - 1] + s[r] + mod - s[l]) % mod;
		lensum[n - i + 1] = lensum[i];
		r--; l++;
	}
	
	//rep(i, n + 1) dbg(i, lensum[i]);
	
	ll lrsum = 0, ans = 0;
	
	for(int i = 1; i < n; i++){
		lrsum += v[i - 1];
		lrsum += v[n - i];
		lrsum %= mod;
		
		ll x = (lensum[i] + mod - lrsum) % mod;
		ans += 2 * f[n] * x % mod * inv[i + 1] % mod * inv[i + 2] % mod;
		ans += f[n] * lrsum % mod * inv[i + 1] % mod;
		ans %= mod;
	}
	ans += f[n] * s[n] % mod;
	cout << ans % mod << endl;
	
	return 0;
}