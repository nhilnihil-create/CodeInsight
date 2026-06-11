#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,k;
ll ans,t;
int main(){
	scanf("%d%d",&n,&k);
	ans=n/k;
	ans=ans*ans*ans;
	if(k%2==0)t=(n+k/2)/k,t=t*t*t;
	cout<<ans+t;
	return 0;
}