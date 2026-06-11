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

int C[510], S[510], F[510];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		cin >> C[i] >> S[i] >> F[i];
	}
	for (int i = 0; i < N - 1; i++) {
		int ans = S[i] + C[i];
		for (int j = i + 1; j < N - 1; j++) {
			if (ans <= S[j]) ans = S[j];
			else {
				if (ans % F[j] != 0) ans += F[j] - (ans % F[j]);
			}
			ans += C[j];
		}
		cout << ans << endl;
	}
	cout << 0 << endl;
}
