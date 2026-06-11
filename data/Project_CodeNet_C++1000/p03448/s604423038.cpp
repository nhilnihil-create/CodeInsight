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
	int A, B, C, X;
	cin >> A >> B >> C >> X;
	int ans = 0;
	for (int i = 0; i <= A; i++) {
		for (int j = 0; j <= B; j++) {
			for (int k = 0; k <= C; k++) {
				if (500 * i + 100 * j + 50 * k == X) ans++;
			}
		}
	}
	cout << ans << endl;
}