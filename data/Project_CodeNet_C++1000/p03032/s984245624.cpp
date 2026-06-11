#include<bits/stdc++.h>
#include<iostream>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 1002
#define i197 1000000007

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<int,ll>Pil;
typedef pair<int,Pil>Piil;
typedef pair<P1,ll> P2;
typedef pair<string,string> Ps;
const ll INF=1000000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};
struct pos{
	// 1 変数を入れる;
	int x,y,sx,sy,cost;
};
ll v[52]={};
ll d[52]={};

int main() {

	int n,k;
	cin>>n>>k;
	rep(i,n){
		cin>>v[i+1];
		d[i+1]=d[i]+v[i+1];
	}
	ll ans=0;
	rep(i,n){
		int t[52]={};
		int s=0;
		ll a=d[i];
		rep(k,i){
			if(v[k+1]<0){
				t[s]=v[k+1];
				s++;
			}
		}
		rep(j,n){
			if(i+j>k||i==n+1-j)break;
			if(v[n+1-j]<0){
				t[s]=v[n+1-j];
				s++;
			}
			a+=v[n+1-j];
			sort(t,t+s);

			ll a2=a;
			rep(l,min(k-i-j,s))a2-=t[l];
			ans=max(ans,a2);
		}
	}
	if(n==1)ans=max(ans,v[1]);
	cout<<ans<<endl;

	return 0;
}
