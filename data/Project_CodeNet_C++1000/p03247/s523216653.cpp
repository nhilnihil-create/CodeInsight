#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1005
struct node{
    ll x,y;
    node(ll r_x=0,ll r_y=0) {x=r_x,y=r_y;}
}p[M];
int n,tp=-1;
ll s[M];
int cnt;
ll dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
char ss[4]={'L','U','R','D'};
void work() {
    for(int i=30;i>=0;i--) s[++cnt]=1ll<<i;
    if(tp==0) s[++cnt]=1;
    cout<<cnt<<'\n';
    for(int i=1;i<=cnt;i++) cout<<s[i]<<' ';
    cout<<'\n';
    for(int i=1;i<=n;i++)
	{
	    ll x=0,y=0;
	    for(int j=1;j<=cnt;j++)
		{
		    ll tx,ty,ax,ay,mn=1e18;
	        int cho;
		    for(int t=0;t<4;t++)
			{
			    tx=x+dx[t]*s[j],ty=y+dy[t]*s[j];
			    if(abs(tx-p[i].x)+abs(ty-p[i].y)<mn)
				{
				    mn=abs(tx-p[i].x)+abs(ty-p[i].y);
				    ax=tx,ay=ty;
				    cho=t;
				}
			}
		    cout<<ss[cho];
		    x=ax,y=ay;
		}
	    cout<<'\n';
	}
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
	{
	    cin>>p[i].x>>p[i].y;
	    if(tp==-1) tp=(abs(p[i].x)+abs(p[i].y))&1;
	    else if(tp!=((abs(p[i].x)+abs(p[i].y))&1)) {tp=2;break ;}
	}
    if(tp==2) cout<<-1<<'\n';
    else work();
    return 0;
}