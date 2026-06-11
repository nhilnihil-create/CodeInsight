#include<bits/stdc++.h>
using namespace std;
#define ll long long
int ans=1e9+7;
int A,B,C,l[15],n;
void dfs(int i,int a,int b,int c,int m)
{
	if(i==n+1){
      	if(!a||!b||!c) return ; 
	    else
	       {
	  	       ans=min(ans,abs(A-a)+abs(B-b)+abs(C-c)+m);
			   return;
	       }
		}
	 dfs(i+1,a+l[i],b,c,m+(a==0?0:10));
	 dfs(i+1,a,b+l[i],c,m+(b==0?0:10));
	 dfs(i+1,a,b,c+l[i],m+(c==0?0:10));
	 dfs(i+1,a,b,c,m);
}
int main()
{
   cin>>n>>A>>B>>C;
   for(int i=1;i<=n;i++) cin>>l[i];
   dfs(1,0,0,0,0);
   cout<<ans;


return 0;
}
