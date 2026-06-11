#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const int MOD = 998244353;
const ll INF = 1000000000000000000;

int H[1010];
int main()
{
	int N, T, A;
	cin >> N >> T >> A;
	for (int i = 0; i < N; i++) cin >> H[i];
	pair<double,int> ans = { mod,0 };
	for (int i = 0; i < N; i++) {
		double t = T - (double)H[i] * 0.006;
		ans = min(ans, { abs(A - t), i + 1 });
	}
	cout << ans.second << endl;
}