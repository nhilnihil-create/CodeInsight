#include<cstdio>
using namespace std;
int a[200005];
int main(){
	int n,i,j=1;
	long long sum,ans=0;
	int yhs;
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	yhs=a[1];
	sum=a[1];
	for(i=1;i<=n;i++){
		while(j<=n&&yhs==sum){
			ans+=j-i+1;
			j++;
			sum+=a[j];
			yhs^=a[j];
		}
		sum-=a[i];
		yhs^=a[i];
	}
	printf("%lld",ans);
	return 0;
}