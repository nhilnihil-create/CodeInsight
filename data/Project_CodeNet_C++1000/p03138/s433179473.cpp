#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 100005;
const int MAX_bit = 45;
ll A[MAX_N],dp0[MAX_bit],dp1[MAX_bit];
int cnt0[MAX_bit],cnt1[MAX_bit];

int main()
{
	int N;
	ll K;
	cin >> N >> K;
	rep(i,N)
	{
		cin >> A[i];
		rep(j,MAX_bit)
		{
			if (A[i] & (1ull << j)) cnt1[j]++;
			else cnt0[j]++;
		}
	}

	for (int i = MAX_bit-2; i >= 0; --i)
	{
		if (K & (1ull << i)) dp0[i] = dp0[i+1] + (1ull << i) * cnt0[i];
		else dp0[i] = dp0[i+1] + (1ull << i) * cnt1[i];
	}
	bool b = false;
	for (int i = MAX_bit-2; i >= 0; --i)
	{
		if ((K & (1ull << i)) && !b)
		{
			b = true;
			dp1[i] = dp0[i+1] + (1ull << i) * cnt1[i];
		}
		else if ((K & (1ull << i)) && b)
		{
			dp1[i] = max(dp0[i+1] + (1ull << i) * cnt1[i], dp1[i+1] + (1ull << i) * max(cnt0[i],cnt1[i]));
		}
		else if (b)
		{
			dp1[i] = dp1[i+1] + (1ull << i) * max(cnt0[i],cnt1[i]);
		}
	}
	/*
	rep(i,MAX_bit)
	{
		if (K & (1 << i)) cout << "1 ";
		else cout << "0 ";
	}
	cout << endl << b << endl;
	cout << dp0[0] << " " << dp1[0] << endl;
	*/
	cout << max(dp0[0],dp1[0]) << endl;
	return 0;
}