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

int cnt[100010];
int main()
{
	int N;
	cin >> N;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		if (a > 100000) ans++;
		else cnt[a]++;
	}
	for (int i = 1; i <= 100000; i++) {
		if (cnt[i] >= i) ans += cnt[i] - i;
		else ans += cnt[i];
	}
	cout << ans << endl;
}
