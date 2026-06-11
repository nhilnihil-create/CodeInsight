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

//繰り返し二乗法
ll mod_pow(ll x,ll n){
	ll res = 1;
	while(n > 0){
		if(n & 1){
			res = res * x % mod;
		}
		x = x * x % mod;
		n >>= 1;
	}
	return res;
}

int main(){
	ll n;cin>>n;
	string s;cin>>s;
	vector<int> a(26,0);
	for(int i = 0; i < n; i++) {
		a[s[i] - 'a']++;
	}
	ll ans = 1;
	for(int i = 0; i < 26; i++) {
		ans *= (a[i] + 1);
		ans %= mod;
	}
	cout << ans - 1 << endl;
	return 0;
}