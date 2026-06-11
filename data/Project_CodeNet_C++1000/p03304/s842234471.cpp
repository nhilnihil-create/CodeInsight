#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;
typedef pair<int, int> P;

int main()
{
	int n, m, d;
	cin >> n >> m >> d;
	if (d == 0) {
		printf("%.7f", (1.0 / n) * (m - 1));
	}
	else {
		printf("%.7f", (2.0 * (n - d) / n / n) * (m - 1));
	}
}
