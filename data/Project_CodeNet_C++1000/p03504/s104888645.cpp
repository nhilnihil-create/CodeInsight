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

int use[100010][40];
int main()
{
	int N, C;
	cin >> N >> C;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int s, t, c;
		cin >> s >> t >> c;
		c--;
		use[s - 1][c]++;
		use[t][c]--;
	}
	for (int i = 0; i < C; i++) {
		for (int j = 1; j < 100010; j++) {
			use[j][i] += use[j - 1][i];
		}
	}
	for (int i = 0; i < 100010; i++) {
		int cnt = 0;
		for (int j = 0; j < C; j++) {
			if (use[i][j] >= 1) cnt++;
		}
		ans = max(ans, cnt);
	}
	/*for (int i = 0; i < C; i++) {
		for (int j = 0; j < 15; j++) {
			cout << use[j][i] << " ";
		}
		cout << endl;
	}*/
	cout << ans << endl;
}