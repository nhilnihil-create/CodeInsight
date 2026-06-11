#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n;
	scanf("%lld",&n);
	ll a[n];
	ll best=0;
	ll sum=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
		best<a[i]?best=a[i]:best=best;
		sum+=a[i];
	}
	if(best<sum-best){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	
}
