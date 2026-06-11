#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int main() {
	long long N,ans=0;
	cin >> N;
	for (long long i = 1; i <= ceil(sqrt(N))+5; i++)
	{
		if (N % i == 0&&N/i>i+1)ans += (N / i) - 1;
	}
	cout << ans;
}
