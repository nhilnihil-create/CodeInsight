#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n;
	cin>>n;
	vector<int>arr(n+1);
	for(int i=1; i<=n; i++)
	 cin>>arr[i];
	vector<int>pf1(n+1);
	vector<int>pf2(n+1);
	int gcd=arr[1];
	pf1[1]=gcd;
	for(int i=2; i<=n; i++){
		pf1[i]=__gcd(gcd,arr[i]);
		gcd=pf1[i];
	}
	gcd=arr[n];
	pf2[n]=gcd;
	for(int i=n-1; i>=1; i--){
		pf2[i]=__gcd(arr[i],gcd);
		gcd=pf2[i];
	}
	int ans=1;
	for(int i=1; i<=n; i++){
		if(i==1)
		{
			ans=max(ans,pf2[i+1]);
		}
		else if(i==n)
		{
			ans=max(ans,pf1[i-1]);
		}
		else{
			int temp=__gcd(pf1[i-1],pf2[i+1]);
			ans=max(ans,temp);
		}
	}
	cout<<ans;
	return 0;
	
	
}