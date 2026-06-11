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

bool can(vi v, int x){
	//dbg(v, x);
	vi dp(20000);
	dp[10000] = 1;
	rep(i, v.size()){
		vi next(20000);
		rep(j, 20000) if(dp[j]){
			if(j + v[i] < 20000) next[j + v[i]] = 1;
			if(j - v[i] >= 0) next[j - v[i]] = 1;
		}
		dp = next;
	}
	return dp[10000 + x];
}

int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	
	string in; cin >> in;
	int x, y; cin >> x >> y;
	int cnt = 0;
	for(int i = 0; i < in.size() && in[i] == 'F'; i++) cnt++;
	x -= cnt;
	in = in.substr(cnt);
	
	cnt = 0;
	bool toX = 1;
	vi a, b;
	rep(i, in.size()){
		if(in[i] == 'T'){
			if(cnt){
				if(toX) a.pb(cnt);
				else b.pb(cnt);
				cnt = 0;
			}
			toX ^= 1;
		}
 		else cnt++;
	}
	if(cnt){
		if(toX) a.pb(cnt);
		else b.pb(cnt);
		cnt = 0;
	}
	
	cout << (can(a, x) && can(b, y) ? "Yes" : "No") << endl;
	
	return 0;
}