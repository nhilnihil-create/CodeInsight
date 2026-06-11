#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

#define INF LLONG_MAX / 5
#define MOD 1000000007
#define int long long
#define rep(i, n) for (int i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define enld endl

signed main() {
	vector<int>V = 
	{
1,
6,
36,
216,
1296,
7776,
46656,
9,
81,
729,
6561,
59049
	};
	int N;
	cin >> N;
	vector<int>dp(N + 1,INF);
	dp[0] = 0;
	rep(i,N+1){
		rep(j, V.size()) {
			if (i - V[j] >= 0) {
				dp[i] = min(dp[i], dp[i - V[j]] + 1);
			}
		}
	}
	cout << dp[N] << enld;
}