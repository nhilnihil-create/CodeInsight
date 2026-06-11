#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> P;
typedef pair<int,int> Pi;
#define rep(i,n) for(ll i=0;i<n;i++)
#define FOR(i,a,b) for(ll i=a;i<b;i++)
#define fi first
#define se second
#define endl "\n"

template<typename T> inline bool chmax(T &a, T b){if(a<b){a=b;return true;}return false;}
template<typename T> inline bool chmin(T &a, T b){if(a>b){a=b;return true;}return false;}
template<typename T> ostream& operator<<(ostream& s,const complex<T>& d) {return s<<"("<<d.real()<<", "<<d.imag()<< ")";}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const pair<T1,T2>& d) {return s<<"("<<d.first<<", "<<d.second<<")";}
template<typename T> ostream& operator<<(ostream& s, const vector<T>& d){int len=d.size();rep(i,len){s<<d[i];if(i<len-1) s<<" ";}return s;}
template<typename T> ostream& operator<<(ostream& s,const vector<vector<T>>& d){int len=d.size();rep(i,len){s<<d[i]<<endl;}return s;}
template<typename T> ostream& operator<<(ostream& s,const set<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T> ostream& operator<<(ostream& s,const multiset<T>& v){s<<"{ ";for(auto itr=v.begin();itr!=v.end();++itr) {if (itr!=v.begin()) {s<< ", ";}s<<(*itr);}s<<" }";return s;}
template<typename T1, typename T2> ostream& operator<<(ostream& s,const map<T1,T2>& m){s<<"{"<<endl;for(auto itr=m.begin();itr!=m.end();++itr){s<<" "<<(*itr).first<<" : "<<(*itr).second<<endl;}s<<"}"<<endl;return s;}

const ll mod=1'000'000'007;
const ll inf=1'000'000'000'000'000'00;
const int INF=1'000'000'000;
const double EPS=1e-10;
const double PI=acos(-1);

int main(){
	cin.tie(0);ios::sync_with_stdio(false);
	int h,w;
	cin>>h>>w;
	vector<string> g(h);
	int cnt=0;
	rep(i,h){
		cin>>g[i];
		rep(j,w){
			if(g[i][j]=='#') cnt++;
		}
	}
	auto bfs=[&](Pi s,Pi go){
		vector<int> dx={1,-1,0,0},dy={0,0,1,-1};
		queue<Pi> que;
		vector<vector<int>> dist(h,vector<int>(w,INF));
		que.push(s);
		dist[s.fi][s.se]=0;
		while(!que.empty()){
			Pi now=que.front();
			que.pop();
			rep(i,4){
				int nx=now.fi+dx[i],ny=now.se+dy[i];
				if(0<=nx && nx<=h-1 && 0<=ny && ny<=w-1){
					if(g[nx][ny]!='#' && dist[nx][ny]==INF){
						dist[nx][ny]=dist[now.fi][now.se]+1;
						que.push(Pi(nx,ny));
					}
				}
			}
		}
		return dist[go.fi][go.se];
	};
	int ret=bfs(Pi(0,0),Pi(h-1,w-1));
	if(ret==INF){
		cout<<-1<<endl;
	}else{
		cout<<h*w-ret-cnt-1<<endl;
	}
}