/*input
1 100000
1
*/
#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <climits>

using namespace std; 

int GCD(int x,int y){return y?GCD(y,x%y):x;}
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,n) for(int i=0;i<(n);i++)
#define repl(i,a,b) for(int i=(a);i<(b);i++)
#define repm(i,a,b) for(int i=(a);i>(b);i--)
#define rept(v) for(auto it=v.begin();it<v.end();it++)
#define all(v) v.begin(),v.end()
const int INF = 1<<30;
typedef long long ll;
typedef pair<int,int> pii;

int const MOD = 1e9+7;
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(0);
	int n, k;
	cin >> n >> k;
	int a[n];
	rep(i, n) cin >> a[i];
	bool dp[k+1];
	memset(dp, 0, sizeof(dp));
	repl(i, 1, k+1) {
		rep(j, n) {
			if(i-a[j]>=0) {
				dp[i]|=!dp[i-a[j]];
			}
		}
	}
	cout << (dp[k] ? "First" : "Second");
	return 0;
}