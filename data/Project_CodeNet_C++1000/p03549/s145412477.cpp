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
	int N, M;
	cin >> N >> M;
	int ans = 0;
	ans = (N - M) * 100;
	ans += M * 1900;
	for (int i = 0; i < M; i++) ans *= 2;
	cout << ans << endl;
}
