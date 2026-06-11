#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;
int A[100010];
int main()
{
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) cin >> A[i];
	ll ans = 2;
	for (int i = K - 1; i >= 0; i--)ans = (ans + A[i] - 1) / A[i] * A[i];
	ll num = ans;
	for (int i = 0; i < K; i++)num -=  num % A[i];
	if (num != 2)
    {
		cout << -1 << endl;
		return 0;
	}
	cout << ans << " ";
	ans = 2;
	for (int i = K - 1; i >= 0; i--)ans = (ans / A[i] + 1) * A[i] - 1;
	cout << ans << endl;
}
