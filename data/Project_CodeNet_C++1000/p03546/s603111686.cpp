#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 100001
#define i197 1000000007

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<int,ll>Pil;
typedef pair<P1,ll> P2;
typedef list<int> li;
typedef list<li> lli;
typedef pair<string,string> Ps;
const ll INF=1000000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};
struct pos{
	// 1 変数を入れる;
	ll a;
	int b;
};
ll dp[10][10];

int main(){

	int h,w;
	cin>>h>>w;
	rep(i,10){
		rep(j,10){
			int c;
			cin>>c;
			dp[i][j]=c;
		}
	}
	rep(k,10){
		rep(i,10){
			rep(j,10){
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	ll total=0;
	rep(i,h){
		rep(j,w){
			int a;
			cin>>a;
			if(a==-1)continue;
			total+=dp[a][1];
		}
	}
	cout<<total<<endl;

	return 0;
}
