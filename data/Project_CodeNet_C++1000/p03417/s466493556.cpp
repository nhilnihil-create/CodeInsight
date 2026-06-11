#include<bits/stdc++.h>
// Begin Header {{{
#define lli long long int
#define rep(i,n) for(lli i=0; i<n; i++)
#define loop(i, j, n) for(lli i=j; i<n; i++)
#define all(x) (x).begin(), (x).end()
constexpr int INF  = 0x3f3f3f3f;
const long long mod=1e9+7;
const double PI = acos(-1);
using namespace std;
using Graph = vector<vector<lli>>;
using P = pair<int, int>;
// }}} End Header

int main(){
	lli n, m, ans;
	cin >> n >> m;
	if(n == 1 || m == 1){
		if(n == m) ans = 1;
		else if(n == 2 || m == 2) ans = 0;
		else ans = max(n, m) -2;
	}else ans = (n-2)*(m-2);
	cout << ans << endl;
	return 0;
}