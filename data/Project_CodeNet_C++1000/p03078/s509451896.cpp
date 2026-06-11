#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<sstream>
#include<vector>
#define inf 2147483647
#define rep(i,a,b) for(int i=a;i<b;i++)
#define  rr read()
#define ll long long
#define repb(i,a,b) for(int i=a;i<=b;i++)
#define CloseIo   ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
int read()
{
    char ch = getchar();
	int x = 0, f = 1;
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while('0' <= ch && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
vector<ll>v[10],v1,v2;
 
int main()
{
CloseIo;
ll a[10],k;
rep(i,0,3)
scanf("%lld",&a[i]);
scanf("%lld",&k);
rep(i,0,3)
{
	 rep(j,0,a[i])
	 {
	 ll t;
	 scanf("%lld",&t);
	 v[i].push_back(t);
	 	
	 }
//	 sort(v[i].begin(),v[i].end(),cmp);
}
//printf("\n\n\n");
rep(i,0,v[0].size())
rep(j,0,v[1].size())
{
	v1.push_back(v[0][i]+v[1][j]);
}
sort(v1.begin(),v1.end(),greater<ll>());
v1.resize(k);
rep(i,0,v1.size())
rep(j,0,v[2].size())
{
	v2.push_back(v1[i]+v[2][j]);
}
sort(v2.begin(),v2.end(),greater<ll>());
rep(i,0,k)
printf("%lld\n",v2[i]);
}
 