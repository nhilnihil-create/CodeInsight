#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
	ll n,k;
	cin>>n>>k;
	vector<ll> a(n);
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a.begin(),a.end());
	vector<bool> dp(k+1,0);
	for(int i=1;i<=k;i++){
		for(int j=0;j<n;j++){
			if(a[j]>i)
			break;
			else 
			dp[i]=dp[i]||(!dp[i-a[j]]);
		}
	}
	if(dp[k])
	cout<<"First"<<endl;
	else 
	cout<<"Second"<<endl;
}