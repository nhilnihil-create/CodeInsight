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
	int a, b, k;
	cin >> a >> b >> k;
	if(a == b){
		cout << a << endl;
		return 0;
	}
	for(int j = a; j<min(a+k, b+1); j++){
		cout << j << endl;
	}
	for(int t = max(a+k, b-k+1); t<=b; t++){
		cout << t << endl;
	}

	return 0;
}