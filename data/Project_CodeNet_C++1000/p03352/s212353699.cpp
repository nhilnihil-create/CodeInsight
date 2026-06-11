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
	int X;
	int ans = 1;
	cin >> X;
	for (int i = 2; i <= X; i++) {
		int tmp = i * i;
		while (tmp <= X) {
			ans = max(ans, tmp);
			tmp *= i;
		}
	}
	cout << ans << endl;
}
