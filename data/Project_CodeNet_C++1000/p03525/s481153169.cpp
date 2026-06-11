//#pragma GCC optimize("Ofast")
//#pragma GCC optimize ("unroll-loops")
//#pragma GCC target ("avx")
#define io_init cin.tie(0);ios::sync_with_stdio(0);cout<<setprecision(10)
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

int main() {
	int N;
	cin >> N;
	vector<int> D(N);
	for (int i = 0; i < N; i++)cin >> D[i];

	vector<int> s(25,0);
	s[0] = 1;
	sort(D.begin(), D.end());
	for (int i = 0; i < N; i++) {
		if (i % 2 == 0) {
			s[D[i]] += 1;
		}
		else {
			s[24 - D[i]] += 1;
		}
	}
	int ans = INF;
	for (int i = 0,cnt = 0,flag = 0; i < 25; i++) {
		//cout << s[i] << " ";
		if (s[i] > 1)ans = 0;
		if (!s[i]) {
			cnt++;
			flag = 1;
		}
		else {
			if (flag) {
				ans = min(ans, cnt+1);
			}
			cnt = 0;
		}
		if (i != 24 && s[i] == 1 && s[i + 1] == 1)ans = min(ans, 1);
	}
	//cout << endl;
	cout << ans << endl;
}