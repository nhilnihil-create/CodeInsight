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

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	int n, cnt[2] = {};
	cin >> n;
	vector<ll> x(n), y(n);
	rep(i, n){
		cin >> x[i] >> y[i];
		cnt[((x[i] + y[i]) % 2 + 2) % 2]++;
	}
	if(cnt[0] && cnt[1]){
		cout << -1 << endl;
		return 0;
	}
	
	vector<ll> ms;
	rep(i, 35) ms.pb(1ll << i);
	if(cnt[0]){
		ms.pb(1);
		rep(i, n) x[i]++;
	}
	
	cout << ms.size() << endl;
	rep(i, ms.size()) cout << ms[i] << (i==ms.size()-1?"\n":" ");
	
	rep(i, n){
		ll u = x[i] + y[i];
		ll v = x[i] - y[i];
		
		auto solve = [](ll val){
			vi res(35);
			ll av = (abs(val) - 1) / 2;
			res[34] = 1;
			rep(i, 34) res[i] = av >> i & 1;
			if(val < 0) rep(i, 35) res[i] ^= 1;
			return res;
		};
		
		vi a = solve(u);
		vi b = solve(v);
		string ans;
		rep(i, 35){
			if(a[i] && b[i]) ans += 'R';
			if(a[i] && !b[i]) ans += 'U';
			if(!a[i] && b[i]) ans += 'D';
			if(!a[i] && !b[i]) ans += 'L';
		}
		if(cnt[0]) ans += 'L';
		cout << ans << endl;
	}
	
	
	return 0;
}