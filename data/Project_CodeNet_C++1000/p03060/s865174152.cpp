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
const ll INF = 1000000000000000000;

int main()
{
	int N;
	int V[21], C[21];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> V[i];
	for (int i = 0; i < N; i++) cin >> C[i];
	int ans = 0;
	int num = -mod;
	for (int i = 0; i < N; i++) {
		ans += max(0, V[i] - C[i]);
	}
	cout << ans << endl;
}
