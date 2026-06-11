#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	long double ans=0.0;
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		long double sum=1.0/n;
		int now=i;
		while(now<k){
			now*=2;
			sum/=2;
		}
		ans+=sum;
	} 
	cout<<fixed<<setprecision(10)<<ans;
    return 0;
}
