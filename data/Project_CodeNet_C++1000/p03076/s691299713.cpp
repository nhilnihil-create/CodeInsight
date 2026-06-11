#include<bits/stdc++.h>
// Begin Header {{{
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
using Graph = vector<vector<ll>>;
#define rep(i,n) for(ll i=0; i<n; i++)
#define loop(i, j, n) for(ll i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const long double PI = acos(-1);
// }}} End Header

int main() {
	vector<int> a(5);
	int max = 0;
	int kazu = 0;
	rep(i,5){
		cin >> a[i];
		int amari;
		if(a[i]%10 == 0) amari = 0;
		else amari = 10-(a[i]%10);
		if(amari >= max){
			max = amari;
			kazu = i;
		}
	}
	int ans = 0;
	rep(i,5){
		if(i == kazu) continue;
		else{
			if(a[i]%10 == 0) ans+=a[i];
			else ans+= ((a[i]/10)*10 + 10);
		}
	}
	cout << ans+a[kazu] << endl;
	return 0;
}