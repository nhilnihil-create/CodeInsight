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
	cin >> N;
	int ans = mod;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		int cnt = 0;
		while (A % 2 == 0) {
			cnt++;
			A /= 2;
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
}