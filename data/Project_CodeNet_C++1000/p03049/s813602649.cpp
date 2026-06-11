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

int main()
{
	int N;
	string S[10010];
	cin >> N;
	for (int i = 0; i < N; i++) cin >> S[i];
	int ans = 0;
	int A = 0, B = 0, same = 0;
	for (int i = 0; i < N; i++) {
		if (S[i][0] == 'B') B++;
		if (S[i][S[i].size() - 1] == 'A') A++;
		if (S[i][0] == 'B' && S[i][S[i].size() - 1] == 'A') {
			same++;
			A--; B--;
		}
		for (int j = 0; j < S[i].size(); j++) {
			if (S[i][j] == 'A' && S[i][j + 1] == 'B') ans++;
		}
	}
	if (same == 0) ans += min(A, B);
	else {
		if (A + B > 0) ans += same + min(A, B);
		else ans += same - 1;
	}
	cout << ans << endl;
}
