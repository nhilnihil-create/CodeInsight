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
    ll n, X, a, ans = INF;
    cin >> n >> X;
    vector<ll> sum(n+1,0);
    for(int i=0;i<n;i++) cin >> a, sum[i+1] = sum[i] + a;
    for(int i=1;i<=n;i++){
    	ll num = X * i + (sum[n] - sum[n-i]) * 5;
    	for(int j=2; (j-1)*i < n && num < ans; j++) 
    		num += (j<<1|1) * (sum[n -(j-1)*i] - sum[max(n-j*i, 0LL)]);
    	ans = min(ans, num);
    }
    cout << ans + n * X << endl;
    return 0;
}

