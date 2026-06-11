#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1000005;
const int MAXM= 15000005;
int l;
int n,m;
struct edge
{
	int u,v,val;
}e[N];

int cnt;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin>>l;
  int n=0,k=l;
  for(int i=25;;i--)
  {
  	if((1<<i)<=l)
  	{
  	  n=i+1;
		break;	
	}
  }
  for(int i=1;i<n;i++)
  {
  	e[cnt].u=i;
  	e[cnt].v=i+1;
  	e[cnt++].val=0;
  	
  	e[cnt].u=i;
  	e[cnt].v=i+1;
  	e[cnt++].val=1<<i-1;
  }
  int res=l-(1<<(n-1));
  int now=1<<(n-1);
  for(int i=n-1;i>=1;i--)
  {
  	if(res>=(1<<i-1))
  	{
  	 res-=1<<i-1;
  	 e[cnt].u=i;
  	 e[cnt].v=n;
  	 e[cnt++].val=now;
  	 now+= 1<<i-1; 
	}
  }
    cout<<n<<" "<<cnt<<endl;
  	for(int i=0;i<cnt;i++)
  	cout<<e[i].u<<" "<<e[i].v<<" "<<e[i].val<<endl;
}