// "include" {{{
#include <deque>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <cstring>
// }}}
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define reps(i,n) for(int i=1;i<=(n);++i)
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int> 
#define int long long
const int INF = 0x3f3f3f3f;
const long long LINF = 0x3f3f3f3f3f3f3f3fLL;
const long long mod = 1000000007;


signed main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n,h,w;
	cin >> n >> h >> w;
	cout << (n - h + 1) * (n - w + 1) << '\n';
	return 0;
}
