//ΔAGC032D
#include<iostream>
#include<cstdio>
#include<fstream>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<cmath>
#include<cstring>
#include<cstdlib>
using namespace std;
typedef long long LL;
typedef double DB;
const int N = 5005;
const LL inf = 1e17;
int n,p[N];
LL a,b,f[N];
int main()
{
	int i,j,o,x,y;
	scanf("%d%d%d",&n,&x,&y);
	a=x,b=y;
	for(i=1;i<=n;i=i+1)
		scanf("%d",p+i);
	p[0]=0,p[n+1]=n+1;
	f[0]=-inf;
	for(i=1;i<=n+1;i=i+1){
		o=-1;
		x=0,y=0;
		for(j=i-1;j>=0;j=j-1){
			if(p[j]>p[i])
				x++;
			else{
				if(p[j]>o){
					f[i]=min(f[i],f[j]+a*x+b*y);
					o=p[j];
				}
				y++;
			}
		}
		//cout<<i<<f[i]+inf<<endl;
	}
	cout<<f[n+1]+inf;
	return 0;
}