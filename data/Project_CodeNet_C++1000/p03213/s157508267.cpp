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

int cnt[110];
int main()
{
	int N;
	cin >> N;
	for (int i = 2; i <= N; i++) {
		int tmp = i;
		for (int j = 2; j <= N; j++) {
			while (tmp % j == 0) {
				tmp /= j;
				cnt[j]++;
			}
		}
	}
	int ans = 0;
	for (int i = 2; i <= N; i++) {
		if (cnt[i] >= 74) ans++;
		if (cnt[i] >= 24) {
			for (int j = i + 1; j <= N; j++) {
				if (cnt[j] >= 2) ans++;
			}
		}
		if (cnt[i] >= 14) {
			for (int j = i + 1; j <= N; j++) {
				if (cnt[j] >= 4)ans++;
			}
		}
		if (cnt[i] >= 4) {
			for (int j = i + 1; j <= N; j++) {
				if (cnt[j] >= 14) ans++;
			}
			for (int j = i + 1; j <= N; j++) {
				if (cnt[j] >= 4) {
					for (int k = j + 1; k <= N; k++) {
						if (cnt[k] >= 2) ans++;
					}
				}
			}
			for (int j = i + 1; j <= N; j++) {
				if (cnt[j] >= 2) {
					for (int k = j + 1; k <= N; k++) {
						if (cnt[k] >= 4) ans++;
					}
				}
			}
		}
		if (cnt[i] >= 2) {
			for (int j = i + 1; j <= N; j++) {
				if (cnt[j] >= 24) ans++;
			}
			for (int j = i + 1; j <= N; j++) {
				if (cnt[j] >= 4) {
					for (int k = j + 1; k <= N; k++) {
						if (cnt[k] >= 4) ans++;
					}
				}
			}
		}
	}
	cout << ans << endl;
}