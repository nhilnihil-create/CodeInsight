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

int D[60];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> D[i];
	}
	D[N] = 0;
	D[N + 1] = 24;
	sort(D, D + N);
	for (int i = 1; i < N; i += 2) {
		D[i] = 24 - D[i];
	}
	sort(D, D + N + 2);
	int ans = 24;
	for (int i = 0; i <= N; i++) {
		ans = min(ans, D[i + 1] - D[i]);
	}
	cout << ans << endl;
}