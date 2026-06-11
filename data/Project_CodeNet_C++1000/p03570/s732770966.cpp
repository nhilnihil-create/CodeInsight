#include <bits/stdc++.h>
using namespace std;
typedef long long int ll ;

#define pb     push_back
#define mp     make_pair
#define all(v) v.begin() , v.end()
#define allr(v) v.rbegin(), v.rend()
const ll INF =  0x3f3f3f3f3f3f3f3f;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9+7;
const int MAX = 12e5+5;

string s;
int a[MAX];
int dp[1<<26];
int ans[MAX];

int main(int argc, char const *argv[])
{
	// ios_base::sync_with_stdio(false);

	// #ifndef ONLINE_JUDGE
	// freopen("in","r",stdin);
	// freopen("out","w",stdout);
	// #endif

	cin >> s;
	a[0] = 0;
	for(int i = 0 ; i < (int)s.size() ; i++){
		int bit = s[i] - 'a';
		a[i+1] = (a[i] ^ (1 << bit));
	}

	for(int i = 0 ; i < (int)(1 << 26) ; i++)
		dp[i] = inf;

	dp[0] = 0;
	ans[0] = 0;

	for(int i = 1 ; i <= (int)s.size() ; i++){
		ans[i] = inf;
		for(int j = -1 ; j < 26 ; j++){
			int msk = a[i];
			if(j >= 0)
				msk ^= (1 << j);
			ans[i] = min(ans[i], 1 + dp[msk]);
		}
		dp[a[i]] = min(ans[i], dp[a[i]]);
	}

	cout << ans[s.size()];
	return 0;
}  