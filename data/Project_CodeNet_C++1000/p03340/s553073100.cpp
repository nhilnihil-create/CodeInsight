#include<iostream>
#include<cstdio>
using namespace std;
const int N=2000010;
int n;
int a[N];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	unsigned long long suma=0,sumb=0,ans=0;
	int j=1;
	for(int i=1;i<=n;i++){
		while(j<=n+1&&suma==sumb){
			suma^=a[j];
			sumb+=a[j];
			j++;
		}
		suma^=a[j-1];
		sumb-=a[j-1];
		suma^=a[i];
		sumb-=a[i];
		ans+=j-i-1;
		j--;
	}
	printf("%lld\n",ans);
	return 0;
}