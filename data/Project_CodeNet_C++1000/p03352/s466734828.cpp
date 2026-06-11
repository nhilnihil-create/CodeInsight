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
	int n;
	cin >> n;
	vector<bool> expo(n+1);
	expo[1] = true;
	for(int b=2; b*b<=n; b++){
		int v = b*b;
		while(v<=n){
			expo[v] = true;
			v*=b;
		}
	}
	for(int i=n; i>=1; i--){
		if(expo[i]){
			cout << i << endl;
			break;
		}
	}
 	return 0;
}