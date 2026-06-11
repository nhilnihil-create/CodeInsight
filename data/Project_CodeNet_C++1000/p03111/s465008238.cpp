#include <bits/stdc++.h>
#define l_ength size
const int inf = (1<<30);
const int mod = 1000000007; // 998244353
using ll = long long;
using namespace std;

int n, a, b, c;
vector<int> l(8, 0);

int ans = inf;

void dfs( int x, int y, int z, int i, int xcnt, int ycnt, int zcnt ){
	if( i == n ){
		if( xcnt*ycnt*zcnt == 0 ) return;
		int synth = 10*(xcnt-1)+10*(ycnt-1)+10*(zcnt-1);
		ans = min( ans, abs(a-x)+abs(b-y)+abs(c-z)+synth );
		return;
	}
	dfs( x, y, z, i+1, xcnt, ycnt, zcnt );
	dfs( x+l[i], y, z, i+1, xcnt+1, ycnt, zcnt );
	dfs( x, y+l[i], z, i+1, xcnt, ycnt+1, zcnt );
	dfs( x, y, z+l[i], i+1, xcnt, ycnt, zcnt+1 );
}

int main(){
	cin >> n >> a >> b >> c;
	for( int i = 0; i < n; ++i ) cin >> l[i];
	dfs( 0, 0, 0, 0, 0, 0, 0 );
	cout << ans << endl;
}