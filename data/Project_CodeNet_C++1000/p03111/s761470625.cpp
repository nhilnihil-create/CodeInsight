#include<bits/stdc++.h>
using namespace std;
long long  d[9],a,b,c,n;
long long f(long long i,long long x,long long y,long long z)
{
	if(i==n){
		if(x==0||y==0||z==0)return INT_MAX;
		return abs(a-x)+abs(b-y)+abs(c-z);}
	return min({f(i+1,x,y,z),10*(x!=0)+f(i+1,x+d[i],y,z),10*(y!=0)+f(i+1,x,y+d[i],z),10*(z!=0)+f(i+1,x,y,z+d[i])});
}
int main()
{
	cin>>n>>a>>b>>c;
	for(int i=0;i<n;i++)cin>>d[i];
	cout<<f(0,0,0,0)<<endl;
}

