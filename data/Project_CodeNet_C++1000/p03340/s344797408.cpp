#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL a[1000010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	LL n;
	cin>>n;
	for(LL i=1;i<=n;i++){
		cin>>a[i];
	}
	LL j=1,s=0,ans=0;
	for(LL i=1;i<=n;i++){
		while(j<=n&&s+a[j]==(s^a[j])){
			s+=a[j];
			j++;
			ans++;
		}
		s-=a[i];
		ans+=j-i-1;
	}
	cout<<ans<<endl;
	return 0;
}
