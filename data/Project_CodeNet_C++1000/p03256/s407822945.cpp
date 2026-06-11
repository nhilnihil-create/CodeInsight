#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i = 0;i < (int)(n);i++)
#define RREP(i,n) for(int i = (int)n-1;i >= 0;i--)
#define FOR(i,s,n) for(int i = s;i < (int)n;i++)
#define RFOR(i,s,n) for(int i = (int)n-1;i >= s;i--)
#define ALL(a) a.begin(),a.end()
#define IN(a, x, b) (a<=x && x<b)
#define BIT(S,i) ((S&(1ll<<i))>0)
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a = b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a = b;return true;}return false;}
constexpr long long INF = 1e18;

signed main(){
	int N,M;
	cin>>N>>M;
	string s;
	cin>>s;
	vector<int>cntA(N),cntB(N);
	vector<vector<int>>g(N);
	REP(i,M){
		int a,b;
		cin>>a>>b;
		a--;b--;
		g[a].push_back(b);
		g[b].push_back(a);
		if(a==b){
			if(s[a]=='A')cntA[a]++;
			else cntB[a]++;
		}else{
			if(s[a]=='A')cntA[b]++;
			else cntB[b]++;
			if(s[b]=='A')cntA[a]++;
			else cntB[a]++;
		}
	}
	queue<int>que;
	vector<int>used(N);
	REP(i,N){
		if(cntA[i]==0||cntB[i]==0){
			que.push(i);
			used[i]=1;
		}
	}
	while(!que.empty()){
		int now = que.front();
		que.pop();
		for(auto e:g[now]){
			if(s[now]=='A'){
				if(used[e]==0&&--cntA[e]==0){
					que.push(e);
					used[e]=1;
				}
			}else{
				if(used[e]==0&&--cntB[e]==0){
					que.push(e);
					used[e]=1;
				}
			}
		}
	}
	REP(i,N){
		if(used[i]==0){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}