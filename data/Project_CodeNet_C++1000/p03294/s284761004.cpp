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
	ll ans = 0;
	int A[3010];
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		ans += A[i] - 1;
	}
	cout << ans << endl;
}
