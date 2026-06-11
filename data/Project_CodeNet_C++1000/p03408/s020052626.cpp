#include<iostream>
#include<vector>
#include<utility>
#include<map>
#include<algorithm>

using namespace std;
using ll = long long;

string s[110], t[110];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)cin >> s[i];

	int M;
	cin >> M;

	for (int i = 0; i < M; i++)cin >> t[i];

	int ans = 0;

	for (int i = 0; i < N; i++) {
		int score = 0;

		for (int j = 0; j < N; j++)if (s[j] == s[i])score++;
		for (int j = 0; j < M; j++)if (t[j] == s[i])score--;

		ans = max(score, ans);
	}

	cout << ans << endl;

}