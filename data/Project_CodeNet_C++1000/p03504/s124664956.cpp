#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;
typedef pair<int, int> P;

int s[100010], t[100010], c[100010];
bool use[40][100010];
int main()
{
	int N, C;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> s[i] >> t[i] >> c[i];
		c[i]--;
		for (int j = s[i]; j <= t[i]; j++) {
			use[c[i]][j] = true;
		}
	}
	int ans = 0;
	int sum = 0;
	for (int i = 0; i <= 100010; i++) {
		sum = 0;
		for (int j = 0; j < C; j++) {
			if (use[j][i]) sum++;
		}
		ans = max(ans, sum);
	}
	cout << ans << endl;
}