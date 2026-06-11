/*#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
*/

#include <bits/stdc++.h>
using namespace std;
#define pi acos(-1)
#define IOS ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define fi first
#define se second
#define pf push_front
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define debug(x) cerr<<#x<<": "<<(x)<<'\n'
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;
const ll mod = 1e9+7;
const ll inf = 0x3f3f3f3f;
const ll nax = 0;
map<ll, ll>cnt;
ll n, m;

int main(){
	IOS
	cin >> n;
	for(int i=0;i<n;++i){
		ll x; cin >> x;
		++cnt[x];
	}
	cin >> m;
	for(int i=0;i<m;++i){
		ll x; cin >> x;
		if(cnt[x]>0){
			cnt[x]--;
		}
		else{
			cout << "NO" << '\n';
			return 0;
  		}
	}
	cout << "YES" << '\n';
}
