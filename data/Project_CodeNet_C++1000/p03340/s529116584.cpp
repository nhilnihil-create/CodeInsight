#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	int n;
	scanf("%lld",&n);
	int a[n+1];
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	int sum=0,Xor=0,j=0,ans=0;
	for(int i=1;i<=n;i++){
		while(j<n&&((sum+a[j+1])==(Xor^a[j+1]))){
			sum+=a[j+1];
			Xor^=a[j+1];
			j++;
		}
		if(sum==Xor){
			ans+=j-i+1;
		}
		sum-=a[i];
		Xor^=a[i];
	}
	printf("%lld\n",ans);
    return 0;
}