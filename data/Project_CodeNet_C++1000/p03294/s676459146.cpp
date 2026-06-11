#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define f first
#define s second
#define all(s) s.begin(), s.end()
#define sz(a) (int)a.size()

const int mod = 1e9+7;

//ll binpow(ll a, ll n);
//ll modp(ll a, ll b, int m);
//ll binmul(ll a, ll b, ll c);

void solve(){
	
}
int a[10001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; cin>>n;
	ll ans = 0;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		ans+=a[i];
	}
	cout<<ans-n<<"\n";
	return 0;
}

//ll binpow (ll a, ll n) {
//	ll res = 1;
//	while (n) {
//		if (n & 1)
//			res *= a;
//		a *= a;
//		n >>= 1;
//	}
//	return res;
//}

//long long modp(long long a, long long b, int m)
//{
//    int result = 1;
//    while (b > 0)
//    {
//        if (b % 2 == 1)
//            result = (result * a) % m;
//        b = b >> 1;
//        a = (a * a) % m;
//    }
//    return result;
//}

//ll binmul(ll a, ll b, ll c) {
//	if(b == 0) return 0;
//	if(b % 2 == 1) {
//		ll x = binmul(a, b-1, c);
//		return (x+a) % c;
//	}
//	ll x = binmul(a, b/2, c);
//	return x * 2 % c;
//}