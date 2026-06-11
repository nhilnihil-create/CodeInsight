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
const ll INF=1<<30;
ll copy(ll x){
	return x;
}

int main(){
	ll n;cin>>n;
	vector<ll> a(n);
	for(ll i = 0; i < n; i++) {
		cin>>a[i];
	}
	if (a[0] != 0LL){
		cout << -1 << endl;
		return 0;
	}

	for (ll i = 1; i < n; i++) {
         if (a[i] - a[i - 1] > 1) {
             cout << -1 << endl;
             return 0;
         }
     }
	ll l = 0LL;
	ll ans = 0LL;
	for(ll i = 1; i < n; i++) {
		if (a[i] == 0LL){
			l = copy(i);
		}
		else{
			if ((a[i] - a[i - 1]) == 1LL){
				ans++;
			}
			else{
				if ((i - l) >= a[i]){
					ans += a[i];
				}
				else{
					cout << -1 << endl;
					return 0;
				}
			}
		}
	}
	cout << ans << endl;

	return 0;
}