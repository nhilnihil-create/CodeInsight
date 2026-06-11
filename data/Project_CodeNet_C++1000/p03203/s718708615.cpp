#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#define MN 40002
#define MM 5000001
#define ll long long
#define ld long double
#define inf 0x7fffffff
#define clz 1000000007
#define ers(arr,val) memset(arr,val,sizeof(arr));
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define repd(i,b,a) for(int i=(b);i>=(a);i--)
#define repe(i,u) for(int i=h[u];i;i=e[i].nx)
using namespace std;
int n,m,k,d=0;
int x[200001],y[200001],o[200001],Ans;
bool cmp(int p,int q){return x[p]==x[q]?y[p]<y[q]:x[p]<x[q];}
int main(){
	scanf("%d%d%d",&n,&m,&k);Ans=n+1;
	rep(i,1,k) scanf("%d%d",&x[i],&y[i]);
	rep(i,1,k) o[i]=i;
	sort(o+1,o+k+1,cmp);
	rep(i,1,k){
		if(x[o[i]]>y[o[i]]+d) {Ans=x[o[i]];break;}
		if(x[o[i]]==y[o[i]]+d) d++;
	}
	printf("%d",Ans-1);
	return 0;
}