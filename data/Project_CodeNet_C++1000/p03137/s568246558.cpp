#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll n,m,sum=0;
	scanf("%lld%lld",&n,&m);
	ll a[m];
	for(int i=0;i<m;i++){
		scanf("%lld",&a[i]);
	}
	sort(a,a+m);
	vector<ll> v;
	for(ll i=1;i<m;i++){
		v.push_back(abs(a[i]-a[i-1]));
		sum+=abs(a[i]-a[i-1]);
	}
	sort(v.rbegin(),v.rend());
	if(n>=m)printf("0\n");
	else{
		for(ll i=0;i<n-1;i++){
		sum-=v[i];
		}
		printf("%lld",sum);
	}
}	
