#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
const int N=1e5+3,inf=0x7fffffff;
int cnt,n,a[N],maxx,fail,minn=inf;
int main(){
	scanf("%d",&n);
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]>maxx) maxx=a[i],fail=i;
	}
	a[fail]=0;
	int mid=maxx/2;
	for(int i = 1;i<=n;i++){
		if(abs(a[i]-mid)<minn){
			minn=abs(a[i]-mid);
			cnt=a[i];
		}
	}
	printf("%d %d",maxx,cnt);
	return 0;
}