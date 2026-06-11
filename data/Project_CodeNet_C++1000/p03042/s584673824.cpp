#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;
#define ll long long
#define FOR(i,n) for(int i=0;i<n;i++)
#define sz(x) (int)(x.size())
#define all(x) (x).begin(),(x).end()
template<typename tp> void read(tp &x) {cin >> x;}
template<typename tp, typename... Args> void read(tp& x, Args&... args) {read(x);read(args...);}
const int mxN = (int)1e5,INF = (int)1e9,MOD = (int)1e9+7;

void solve()
{
	char a[3],b[3];
	FOR(i,2)read(a[i]);
	FOR(i,2)read(b[i]);
	a[2] = b[2] = 0;
	int x = atoi(a),y = atoi(b);
	if((x>12 && y>12) ||(x==0&&y==0))cout << "NA\n";
	else if(x==0) cout << (y<=12?"YYMM":"NA");
	else if(y==0) cout << (x<=12?"MMYY":"NA");
	else if(x<=12 && y<=12)cout << "AMBIGUOUS";
	else if(x<=12)cout << "MMYY";
	else cout << "YYMM";
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int test = 1;
	//read(test);
	while(test--)
		solve();
	return 0;
}

