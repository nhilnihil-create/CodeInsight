#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

vector<int> S[2];
int main()
{
	int N; cin >> N;
	int ans = 0;
	if (N % 2 == 0) {
		for (int i = 1; i <= N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (j != N - i + 1) {
					ans++;
					S[0].push_back(i);
					S[1].push_back(j);
				}
			}
		}
	}
	else {
		for (int i = 1; i < N; i++) {
			for (int j = i + 1; j <= N; j++) {
				if (j != N - i) {
					ans++;
					S[0].push_back(i);
					S[1].push_back(j);
				}
			}
		}
	}
	cout << ans << endl;
	for (int i = 0; i < S[0].size(); i++) {
		cout << S[0][i] << " " << S[1][i] << endl;
	}
}