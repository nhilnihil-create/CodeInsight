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
bool calc(int n, int a, int b){
	int sum =0;
	while(n>0){
		sum+=n%10;
		n/=10;
	}
	if(sum>=a && sum<=b) return true;
	else return false;
}
int main() {
	int n, a, b, ans = 0;
	cin >> n >> a >> b;
	loop(i, 1, n+1) if(calc(i, a, b)) ans+=i;
	cout << ans << endl;
	return 0;
}