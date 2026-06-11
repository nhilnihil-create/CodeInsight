#include<bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;

ll cal(ll a, ll b, ll c, ll d){
	ll mx = max(max(a,b),max(c,d));
	ll mn = min(min(a,b),min(c,d));
	return mx - mn;
}

int main(){
	int n;
	cin>>n;
	vector<ll> arr(n);
	for(int i = 0; i < n; i++) cin>>arr[i];
	for(int i = 1; i < n; i++) arr[i]+=arr[i-1];

	int p = 0;
	int s = 2;
	ll ans = inf;
	for(int i = 1; i < n-2; i++){
		while(p<=i && abs((arr[i]-arr[p]) - arr[p])>=abs((arr[i] - arr[p+1]) - arr[p+1])) p++;
		while(s<n-1 && abs((arr[n-1] - arr[s]) - (arr[s] - arr[i]))>=abs((arr[n-1] - arr[s+1]) - (arr[s+1] - arr[i]))) s++;
		ans = min(ans,cal(arr[p],arr[i]-arr[p],arr[s]-arr[i],arr[n-1]-arr[s]));
	}
	cout<<ans;
}