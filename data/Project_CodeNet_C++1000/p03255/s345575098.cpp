#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=2e5+10;
ll n,f,x[maxn],ans;
ll sum[maxn];

int main(){
	cin>>n>>f;
	for(int i=1;i<=n;++i){
		cin>>x[i];
		sum[i]=sum[i-1]+x[i];
	}
	ans=1e18;
	for(int i=1;i<=n;++i){
		ll res=f*(n+i)+(sum[n]-sum[n-i])*5;
		for(int j=n-i,k=5;j>0&&res<ans;j-=i,k+=2)
			res+=(sum[j]-sum[max(0,j-i)])*k;
		ans=min(ans,res);
	}
	cout<<ans<<endl;
	return 0;
}