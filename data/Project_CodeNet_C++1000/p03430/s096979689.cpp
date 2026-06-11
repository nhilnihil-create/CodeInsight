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

int n, K, dp[301][301][301];
string s;

int rec(int i, int j, int k){
	int &res = dp[i][j][k];
	if(res >= 0) return res;
	res = 0;
	
	if(i > 0) res = max(res, rec(i - 1, j, k));
	if(j < n) res = max(res, rec(i, j + 1, k));
	if(i > 0 && j < n){
		int nk = k - (s[i - 1] != s[j]);
		if(nk >= 0) res = max(res, 1 + rec(i - 1, j + 1, nk));
	}
	return res;
}
int main(){
	cin.tie(0); cin.sync_with_stdio(0);
	cin >> s >> K;
	n = s.size();
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	rep(i, n + 1) ans = max(ans, 2 * rec(i, i, K));
	rep(i, n) ans = max(ans, 2 * rec(i, i + 1, K) + 1);
	cout << ans << endl;
	return 0;
}