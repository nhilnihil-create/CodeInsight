#include<bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007
#define Vi vector<int>
#define Vl vector<long long>
#define pb(a) push_back(a)

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<P1,ll> P2;
const ll INF=10000000000000000001;
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};
struct edge{int to,cost;};
struct pos{
	int x,y,cost;
};
int dp[1001][1001]={};
char c[1001][1001]={};

int main() {

	int h,w;
	cin>>h>>w;

	queue<pos> que;
	rep(i,h){
		rep(j,w){
			cin>>c[j][i];
			if(c[j][i]=='#'){
				int sj=j,si=i;
				pos pos1={sj,si,0};
				que.push(pos1);
			}
		}
	}

	int ans=0;
	while(!que.empty()){
		pos pos2=que.front();que.pop();
		ans=max(ans,pos2.cost);
		if(c[pos2.x+1][pos2.y]=='.'&&dp[pos2.x+1][pos2.y]==0){
			dp[pos2.x+1][pos2.y]=1;
			pos pos3={pos2.x+1,pos2.y,pos2.cost+1};
			que.push(pos3);
		}
		if(c[pos2.x-1][pos2.y]=='.'&&dp[pos2.x-1][pos2.y]==0){
			dp[pos2.x-1][pos2.y]=1;
			pos pos4={pos2.x-1,pos2.y,pos2.cost+1};
			que.push(pos4);
		}
		if(c[pos2.x][pos2.y+1]=='.'&&dp[pos2.x][pos2.y+1]==0){
			dp[pos2.x][pos2.y+1]=1;
			pos pos5={pos2.x,pos2.y+1,pos2.cost+1};
			que.push(pos5);
		}
		if(c[pos2.x][pos2.y-1]=='.'&&dp[pos2.x][pos2.y-1]==0){
			dp[pos2.x][pos2.y-1]=1;
			pos pos6={pos2.x,pos2.y-1,pos2.cost+1};
			que.push(pos6);
		}
	}

	cout<<ans<<endl;

	return 0;
}
