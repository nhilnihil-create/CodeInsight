#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<climits>
using namespace std;
const int N=1e5+3;
int n;
int a[N],d[N];
int maxx,mid,now=INT_MAX,ans,fail;
int main(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(maxx<a[i]) maxx=a[i],fail=i;
	}
	a[fail]=0;
	mid = maxx/2;
	for(int i = 1;i<=n;i++){
		int k = abs(a[i]-mid);
		if(k<now) now=k,ans=a[i];
	}
	printf("%d %d",maxx,ans);
	return 0;
}