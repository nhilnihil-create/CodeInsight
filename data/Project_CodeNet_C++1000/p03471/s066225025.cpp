#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f40;
const long long mod=1e9+7;
const long double PI = acos(0);
template <class T>void UNIQUE(vector<T> &x){
	sort(all(x));
	x.erase(unique(all(x)), x.end());
}

// }}} End Header
int main() {
	ll n, y;
	cin >> n >> y;

	rep(i, n+1){
		rep(j, n+1){
			int k = n-(i+j);
			if(k >= 0){
				if(i*10000+j*5000+k*1000 == y){
					cout << i << " " << j << " " << k << endl;
					return 0;
				}
			}
		}
	}
	cout << "-1 -1 -1" << endl;
	return 0;
}