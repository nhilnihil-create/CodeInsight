#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long ll;
typedef pair<ll,ll> P;
const ll mod=1000000007;
const ll LINF=1LL<<60;
const int INF=1<<30;

vector<ll>  divisor(ll n){
	vector<ll> a;
	for(ll i = 1; i*i <= n; i++) {
		if (n % i == 0){
			a.pb(i);
			if (i != n/i){
				a.pb(n / i);
			}
		}
	}
	return a;
} 


int main(){
	ll n;cin>>n;
	vector<ll> a = divisor(n);
	ll ans = 0;
	for(int i = 0; i < a.size(); i++) {
		// cout << a[i] << endl;
		// cout << (n - a[i]) / a[i] << endl;
		ll div = (n - a[i])/ a[i];
		if ( div != 0LL && n / div == n % div)ans += div;
	}
	cout << ans << endl;
	return 0;
}