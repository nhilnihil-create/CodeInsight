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

int k[11], s[11][11];
int p[11];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> k[i];
		for (int j = 0; j < k[i]; j++) {
			cin >> s[i][j];
			s[i][j]--;
		}
	}
	for (int i = 0; i < M; i++) cin >> p[i];
	int ans = 0;
	for (int bit = 0; bit < (1 << N); bit++) {
		bool on[11] = { false };
		int tmp = bit;
		for (int i = 0; i < N; i++) {
			if (tmp % 2 == 1) on[i] = true;
			else on[i] = false;
			tmp /= 2;
		}
		bool plus = true;
		for (int i = 0; i < M; i++) {
			int cnt = 0;
			for (int j = 0; j < k[i]; j++) {
				if (on[s[i][j]]) cnt++;
			}
			if (cnt % 2 != p[i]) plus = false;
		}
		if (plus) ans++;
	}
	cout << ans << endl;
}
