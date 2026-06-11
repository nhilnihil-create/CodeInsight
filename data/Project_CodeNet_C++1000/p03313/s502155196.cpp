#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define pii pair<int,int>
int n,a[1000005],ans;
pii Max[1000005];
void fun(int x,pii &y){
	if(x==y.F||x==y.S)return;
    if(a[x]>a[y.F])y.S=y.F,y.F=x;
    else if(a[x]>a[y.S])y.S=x;
}
int main(){
	scanf("%d",&n);
	int sta=1<<n;
	for(int i=0;i<sta;i++){
		scanf("%d",&a[i]);
		Max[i].F=i;
		Max[i].S=sta;
	}
	for(int i=1;i<sta;i++)
		for(int j=0;j<n;j++)
			if(i&(1<<j)){
				int k=i^(1<<j);
				fun(Max[k].F,Max[i]);
				fun(Max[k].S,Max[i]);
			}
	for(int i=1;i<sta;i++){
		ans=max(ans,a[Max[i].F]+a[Max[i].S]);
		printf("%d\n",ans);
	}
}