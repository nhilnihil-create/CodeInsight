#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=mod*mod*3LL;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    ll maki = 1 << n;
    vector<ll> a(maki);
    for(int i=0;i<maki;i++) cin >> a[i];
    vector<ll> dp(maki, 0);
    for(int i=1;i<maki;i++){
    	dp[i] = max(dp[i-1], dp[i]);
    	for(int j=0;j<n;j++)if(i>>j & 1){
    		dp[i] = max(dp[i], a[i] + a[i-(1<<j)]);
    		int num = i-(1<<j);
    		for(int k=j+1;k<n;k++)if(i>>k & 1){
    			if((num|(i-(1<<k))) <= i){
    				if(a[num&(i-(1<<k))] == a[num] && a[num] == a[i-(1<<k)]) continue;
    				dp[i] = max(dp[i], a[num] + a[i-(1<<k)]);
    			}
    		}
    		
    	}
    	for(int j=0;j<n;j++)if(i>>j & 1){
    		a[i] = max(a[i], a[i-(1<<j)]);
    	}
    }
    for(int i=1;i<maki;i++){
    	cout << dp[i] << endl;
    }
    return 0;
}
