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

int B[21];
int main()
{
	int N, M, C;
	cin >> N >> M >> C;
	for (int i = 0; i < M; i++) cin >> B[i];
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int sum = 0;
		for (int j = 0; j < M; j++) {
			int A;
			cin >> A;
			sum += A * B[j];
		}
		if (sum + C > 0) ans++;
	}
	cout << ans << endl;
}
