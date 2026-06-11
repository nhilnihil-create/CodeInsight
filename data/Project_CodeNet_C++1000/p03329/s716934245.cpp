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
	int N; cin >> N;
	int ans = mod;
	int num, sum;
	for (int i = 0; i <= N; i++) {
		sum = 0;
		num = i;
		while (num > 0) {
			sum += num % 6;
			num /= 6;
		}
		num = N - i;
		while (num > 0) {
			sum += num % 9;
			num /= 9;
		}
		ans = min(ans, sum);
	}
	cout << ans << endl;
}