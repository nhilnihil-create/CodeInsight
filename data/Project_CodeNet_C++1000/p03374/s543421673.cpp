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

ll solve(int n, ll c, vector<ll> &x, vector<ll> &v){
	vector<ll> mx(n + 1);
	rep(i, n){
		mx[i + 1] = mx[i] + v[i] - x[i] + (i ? x[i - 1] : 0ll);
	}
	rep(i, n) mx[i + 1] = max(mx[i + 1], mx[i]);
	
	ll ans = mx[n], sum = 0;
	for(int i = n - 1; i >= 0; i--){
		sum += v[i] - 2 * ((i == n - 1 ? c : x[i + 1]) - x[i]);
		ans = max(ans, mx[i] + sum);
	}
	return ans;
}
int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	int n; ll c; cin >> n >> c;
	vector<ll> x(n), v(n);
	rep(i, n) cin >> x[i] >> v[i];
	
	ll ans = 0;
	rep(it, 2){
		ans = max(ans, solve(n, c, x, v));
		reverse(all(x));
		reverse(all(v));
		rep(i, n) x[i] = c - x[i];
	}
	cout << ans << endl;
	return 0;
}