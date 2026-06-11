// by Balloons
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define mpr make_pair
#define debug() puts("okkkkkkkk")
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)

using namespace std;

typedef long long LL;

const int inf = 1e9,maxn=3e5+5;

int n,m,q,a[maxn],b[maxn],ta[maxn];

int work(int x){
	int r=inf,st=0,pos=0;
	for(int i=1;i<=n+1;i++){
		if(a[i] >= a[x]){
			if(st == 0)st = i;
		}else{
			if(st && i-st>=m){
				int bc = 0;
				for(int j=st;j<=i-1;j++){
					b[++ bc]=a[j];
				}
				sort(b+1,b+bc+1);
				for(int j=1;j+m-1<=bc;j++)
					ta[++pos]=b[j];
			}
			st = 0;
		}
	}
	if(pos < q)return inf;
	sort(ta+1,ta+pos+1);
	return ta[q]-a[x];
}

int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	int ans = inf;
	for(int i=n;i>=1;i--){
		ans = min(ans,work(i));
	}
	printf("%d\n",ans);

	return 0;
}
