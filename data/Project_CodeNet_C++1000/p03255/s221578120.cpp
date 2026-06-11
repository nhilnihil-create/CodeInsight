#include<stdio.h>
#include<algorithm>
using namespace std;
typedef unsigned long long ll;
const ll inf=-1;
int a[200010];
ll s[200010];
int get(int i){
	return i==1?5:i*2+1;
}
int main(){
	int n,i,j,k;
	ll X,ans,t;
	scanf("%d%llu",&n,&X);
	for(i=1;i<=n;i++){
		scanf("%d",a+i);
		s[i]=s[i-1]+a[i];
	}
	ans=inf;
	for(k=1;k<=n;k++){
		j=0;
		t=0;
		for(i=n;i>0;i-=k){
			j++;
			t+=get(j)*(s[i]-s[max(i-k,0)]);
		}
		ans=min(ans,t+k*X);
	}
	printf("%llu",ans+n*X);
}