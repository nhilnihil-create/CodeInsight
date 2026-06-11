    #include<bits/stdc++.h>
     
    using namespace std;
     
    #define endl '\n'
     
    typedef long long ll;
     
    struct block{
    	ll s, w, v;
    };
     
    bool cmp(block a, block b){
    	return a.s + a.w > b.s + b.w;
    }
     
    int main(){
    	ios_base::sync_with_stdio(0);
    	cin.tie(0);
     
    	const ll maxn = 1e5 + 4;
    	
    	ll n;
    	cin >> n;
    	vector<block> a(n);
     
    	for(ll i = 0; i < n; i++)
    		cin >> a[i].w >> a[i].s >> a[i].v;
     
    	sort(a.begin(), a.end(), cmp);
    	
    	vector<vector<ll>> dp(2, vector<ll>(maxn));
    	
    	for(ll i = n - 1; i >= 0; i--){
    		
    		for(ll j = 0; j < maxn; j++){
    			dp[i % 2][j] = dp[(i + 1) % 2][j];
    			if(j >= a[i].w)
    				dp[i % 2][j] = max(dp[i % 2][j], a[i].v + dp[(i + 1) % 2][min(j - a[i].w, a[i].s)]);
    		}
    	}
    	
    	ll ans = 0;
    	for(ll i = 0; i < maxn; i++)
    		ans = max(ans, dp[0][i]);
    	
    	cout << ans << endl;
    	
    	return 0;
    }