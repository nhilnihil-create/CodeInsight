#include<bits/stdc++.h>
using namespace std;
bool isodd8(int n){
	if(n%2==0)return 0;
	int sum=0;
	for(int i=1;i*i<=n;i++)
	if(n%i==0){
		if(i*i==n)sum++;
		else sum+=2;
	}
	return sum==8;
}
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int n;
	cin>>n;
	if(n<105)cout<<0;
	else{
		int ans=1;
		for(int i=106;i<=n;i++)if(isodd8(i))ans++;
		cout<<ans<<endl;
	}
    return 0;
}
