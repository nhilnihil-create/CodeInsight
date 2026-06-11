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
	
	int n; cin >> n; n--;
	if(n == 1){
		cout << "2 2" << endl;
		cout << "1 2 0" << endl;
		cout << "1 2 1" << endl;
		return 0;
	}
	
	vi d;
	for(int m = n; m; m /= 2) d.pb(m % 2);
	
	int N = d.size();
	vector<tuple<int,int,int>> e;
	for(int i = 0; i < N - 1; i++){
		e.emplace_back(i, i + 1, 0);
		e.emplace_back(i, i + 1, 1 << N - i - 2);
	}
	int sum = 1 << N - 1;
	for(int i = N - 2; i > 0; i--){
		if(d[i]){
			e.emplace_back(0, N - i - 1, sum);
		}
		sum += d[i] << i;
	}
	if(d[0]) e.emplace_back(0, N - 1, sum + 1);
	e.emplace_back(0, N - 1, sum);
	
	dbg(d, sum);
	
	cout << N << " " << e.size() << endl;
	for(auto j : e) cout << get<0>(j)+1 << " " << get<1>(j)+1 << " " << get<2>(j) << endl;
	
	return 0;
}