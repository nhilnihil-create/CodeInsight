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


int main()
{
	int N, K;
	cin >> N >> K;
	double ans = 0.0;
	for (int i = 1; i <= N; i++) {
		int num = i;
		double sum = 1.0 / N;
		while (num < K) {
			sum /= 2.0;
			num *= 2;
		}
		ans += sum;
	}
	printf("%.10f\n", ans);
}
