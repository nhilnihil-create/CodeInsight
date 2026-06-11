#include<bits/stdc++.h>
#define ll long long 
#define clr(c) memset(c,0,sizeof(c))
#define inf 0x7fffffff
const int mod=1e9+7;
const int M=4e5+5;
const int N=2e5+10;
using namespace std;
inline ll read()
{
	ll sum=0,b=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') b=-1; c=getchar();}
	while(isdigit(c)){sum=sum*10+c-'0';c=getchar();}
	return b*sum;
}
ll t,n,m,k;
ll a,b,c;
ll ans;
int main()
{
	ll A,B;
  	A=read();
  	B=read();
  
  	ll yard;
  	
   	yard=(A*B)-(A+B-1);
  	cout<<yard;
  
  
	
	return 0;
}  