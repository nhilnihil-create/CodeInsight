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
	int n, a, b; cin >> n >> a >> b;
	
	if(a + b > n + 1 || (ll)a * b < n){
		cout << -1 << endl;
		return 0;
	}
	vi v, u(n);
	rep(i, n) v.pb(i % a);
	int cnt = 0;
	for(int i = n - 1, p = 0; i >= 0; i--){
		if(v[i] == 0){
			u[i] += p;
			p = n - i;
			cnt++;
		}
		else u[i] += p;
	}
	cnt = b - cnt;
	//dbg(v); dbg(u); dbg(cnt);
	
	for(int i = (n - 1) / a * a; i >= 0; i -= a){
		int r = min(i + a, n);
		
		if(cnt >= r - i - 1){
			reverse(v.begin() + i, v.begin() + r);
			cnt -= r - i - 1;
		}
		else{
			reverse(v.begin() + i, v.begin() + i + cnt);
			rotate(v.begin() + i, v.begin() + i + cnt, v.begin() + r);
			break;
		}
	}
	//dbg(v); dbg(u);
	
	rep(i, n) cout << v[i] + u[i] + 1 << (i==n-1?"\n":" ");
	
	return 0;
}