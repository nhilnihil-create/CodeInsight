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

int sum[100010];
int main()
{
	int N, Q;
	string S;
	cin >> N >> Q >> S;
	for (int i = 1; i < N; i++) {
		sum[i] = sum[i - 1];
		if (S[i] == 'C' && S[i - 1] == 'A') sum[i]++;
	}
	while (Q--) {
		int l, r;
		cin >> l >> r;
		cout << sum[r - 1] - sum[l - 1] << endl;
	}
}