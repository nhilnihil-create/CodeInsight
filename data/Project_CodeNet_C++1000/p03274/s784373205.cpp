 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;
 const ll MOD = 1000000007;
 // const ll INF = 1000000000000000000LL;

int main() {
	ll n,k;
	cin >> n >> k;
	vector<ll> x(n);
	rep(i,n) cin >> x[i];
	ll ans = INF;
	for(ll i=k-1;i<n;i++){
		ll left = i-k+1;
		ll right = i;
		ll cur;
		if(x[left]*x[right]>=0)
			cur = max(abs(x[right]),abs(x[left]));
		else
			cur = abs(x[right])+abs(x[left])+min(abs(x[right]),abs(x[left]));
		
		ans = min(ans,cur);
	}
	cout << ans << endl;
	return 0;
}
