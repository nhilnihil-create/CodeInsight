#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

long long modpow(long long a, long long n) {
    long long res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    ll n = s.length();
    vector<ll> a(n+1, 0LL), c(n+2, 0LL), le(n+1, 0LL), ri(n+2, 0LL);
    s = " " + s;
    for(int i=1;i<=n;i++){
    	if(s[i] == 'A') a[i]++;
    	if(s[i] == '?') le[i]++;
    	a[i] += a[i-1];
    	le[i] += le[i-1];
    }
    for(int i=n;i>=1;i--){
    	if(s[i] == 'C') c[i]++;
    	if(s[i] == '?') ri[i]++;
    	c[i] += c[i+1];
    	ri[i] += ri[i+1];
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
    	if(s[i] == '?' || s[i] == 'B'){
    		ll num1, num2;
    		num1 = (modpow(3LL, le[i-1]) * a[i-1]) % mod;
    		num1 += (le[i-1] * modpow(3LL, le[i-1] - 1)) % mod;
    		num2 = (modpow(3LL, ri[i+1]) * c[i+1]) % mod;
    		num2 += (ri[i+1] * modpow(3LL, ri[i+1] - 1)) % mod;
    		num1 %= mod;
    		num2 %= mod;
    		ans += (num1 * num2)% mod;
    		ans %= mod;
    	}
    }
    cout << ans << endl;
    return 0;
}
