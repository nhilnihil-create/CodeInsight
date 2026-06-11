#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
using namespace std;
const int mod = 1000000007;
#define ll long long

int main()
{
	int N;
	ll Z, W, a[2010];
	cin >> N >> Z >> W;
	for (int i = 0; i < N; i++)cin >> a[i];
	if (N == 1) cout << abs(a[0] - W) << endl;
	else cout << max(abs(a[N - 2] - a[N - 1]), abs(a[N - 1] - W)) << endl;
}