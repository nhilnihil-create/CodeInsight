#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, m, n) for(ll i = m; i <= n; i++)
#define per(i, m, n) for(ll i = m; i >= n; i--)
#define pb push_back
#define mp make_pair
#define pii pair<ll, ll> 
#define vi vector<ll> 
#define vll vector<ll> 
#define sz(v) (ll) v.size()
const ll INF = 0x3f3f3f3f;

const ll maxn = 2e5 + 5;

ll a[maxn], sum[maxn], N; 

int main() {
    ios::sync_with_stdio(false); 
    cin.tie(0); cout.tie(0); 
    cin >> N;
    rep(i, 1, N) cin >> a[i], sum[i] = sum[i - 1] + a[i];
    ll ans = 1e18; 
    // ll mid1 = 1, first_sum = a[1], second_sum = 0, third_sum = 0, fourth_sum = sum[N] - sum[2], mid2 = 2;
    ll mid1 = 1, mid2 = 2, first_sum, second_sum, third_sum, fourth_sum; 
    for (ll i = 2; i <= N - 2; i++) {
    	// 1 - i is the first half, while i + 1 - N is the second half;
    	first_sum = sum[mid1], second_sum = sum[i] - sum[mid1]; 
    	ll temp = abs(first_sum - second_sum), temp_mid = mid1; 
    	// 1 ~ mid is first_sum, mid + 1 ~ i is second_sum; want to evenly distribute sum1 and sum2; 
    	for (ll l = temp_mid + 1; l <= i - 1; l++) {
    		first_sum += a[l];
    		second_sum -= a[l]; 
    		if (abs(first_sum - second_sum) <= temp) temp = abs(first_sum - second_sum), mid1 = l; 
    		else break; 
    	} 
    	// cout << sum[mid1] << " " << sum[i] - sum[mid1] << endl;  
    	// third_sum -= a[i]; 
    	third_sum = sum[mid2] - sum[i], fourth_sum = sum[N] - sum[mid2]; 
    	temp = abs(third_sum - fourth_sum), temp_mid = mid2;
    	// i + 1 ~ mid2 is third_sum, mid2 + 1 ~ N is the fourth_sum; 
    	for (ll r = temp_mid + 1; r <= N - 1; r++) {
    		third_sum += a[r], fourth_sum -= a[r]; 
    		if (abs(third_sum - fourth_sum) <= temp) temp = abs(third_sum - fourth_sum), mid2 = r;
    		else break;
    	}  
    	// cout << sum[mid2] - sum[i] << " " << sum[N] - sum[mid2] << endl; 
    	ll minn = min(min(sum[mid1], sum[i] - sum[mid1]), min(sum[mid2] - sum[i], sum[N] - sum[mid2])); 
    	ll maxx = max(max(sum[mid1], sum[i] - sum[mid1]), max(sum[mid2] - sum[i], sum[N] - sum[mid2])); 
    	ans = min(ans, maxx - minn); 
    }
    cout << ans << endl; 
    return 0; 
}