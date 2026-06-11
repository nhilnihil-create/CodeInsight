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

int P[200010];
bool a[200010];
bool l[200010];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> P[i];
	for (int i = 0; i < N; i++) {
		a[P[i]] = true;
		if (a[P[i] - 1]) {
			l[P[i]] = true;
		}
	}
	int ans = 0, cnt = 1;
	//for (int i = 1; i <= N; i++) cout << l[i] << " ";
	for (int i = 2; i <= N; i++) {
		if (l[i]) cnt++;
		else {
			ans = max(ans, cnt);
			cnt = 1;
		}
	}
	ans = max(ans, cnt);
	cout << N - ans << endl;
}