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
const int MOD = 998244353;
const ll INF = 1000000000000000000;

int H[110], h[110];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> h[i];
	int ans = 0;
	bool loop = true;
	while (loop) {
		loop = false;
		for (int i = 0; i < N; i++) {
			if (H[i] < h[i]) {
				if (!loop) ans++;
				loop = true;
				H[i]++;
				if (H[i + 1] >= h[i + 1]) break;
			}
		}
	}
	cout << ans << endl;
}