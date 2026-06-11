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

int cnt[31];
int main()
{
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int K;
		cin >> K;
		for (int j = 0; j < K; j++) {
			int A;
			cin >> A;
			A--;
			cnt[A]++;
		}
	}
	int ans = 0;
	for (int i = 0; i < M; i++) {
		if (cnt[i] == N) ans++;
	}
	cout << ans << endl;
}
