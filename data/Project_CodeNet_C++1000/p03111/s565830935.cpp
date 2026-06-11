#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
   int n,a,b,c,l[20],ans=1e9+7,N,m;
   cin>>n>>a>>b>>c;
   for(int i=1;i<=n;i++) cin>>l[i],
   N=pow(4,n);
   for(int i=0;i<N;i++)
   {
   	  int A=0,B=0,C=0;m=0;
   	  int x=i;
   	  for(int j=1;j<=n;j++){
   	  	if(x%4==1) {if(A>0) m+=10;A+=l[j]; }	
   	  	if(x%4==2) {if(B>0) m+=10;B+=l[j]; }	 
   	  	if(x%4==3) {if(C>0) m+=10;C+=l[j];  }
   	  	x=x/4;
		 }
		 if(A==0||B==0||C==0) continue;
		 m+=abs(A-a)+abs(B-b)+abs(C-c); //cout<<m<<" ";
		 ans=min(ans,m);
   }
  
  cout<<ans;

return 0;
}
