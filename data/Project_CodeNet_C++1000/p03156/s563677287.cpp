#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define debug(x) cerr << #x << " " << x << '\n'
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pli = pair<ll,int>;
const int INF = 0x3f3f3f3f, N = 105;
const ll LINF = 1e18 + 5;
int n, p[N], a, b;
int main()
{
 	ios::sync_with_stdio(false);
 	cin.tie(0);
 	cin >> n;
 	cin >> a >> b;
 	int x = 0, y = 0, z = 0;
 	for(int i=1; i<=n; i++)
 	{
 		cin >> p[i];
 		if(p[i]<=a) x++;
 		else if(p[i]<=b) y++;
 		else z++;
 	}
 	int res = min(x, min(y, z));
 	cout << res;
	return 0;
}
