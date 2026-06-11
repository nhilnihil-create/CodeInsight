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
	lli n, a, b, c, d, e;
	cin >> n >> a >> b >> c >> d >> e;
	lli kaisu = n/min({a, b, c, d, e}) +1;
	if(n%min({a, b, c, d, e}) == 0) kaisu--;
	cout << kaisu+4 << endl;
	return 0;
}