#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 200005;
ll A[MAX_N];

ll f(ll m,int N)
{
	ll res = 0;
	rep(i,N)
	{
		res += abs(A[i]-m);
	}
	return res;
}

int main()
{
	int N;
	cin >> N;
	rep(i,N)
	{
		cin >> A[i];
		A[i] -= i+1;
	}
	sort(A,A+N);
	ll ans = 0;
	if (N % 2 == 1)
	{
		ll m = A[N/2];
		ans = f(m,N);
	}
	else
	{
		if ((A[N/2-1]+A[N/2]) % 2 == 0)
		{
			ans = f((A[N/2-1]+A[N/2]) / 2,N);
		}
		else
		{
			ans = min(f(A[N/2-1],N),f(A[N/2],N));
		}
	}
	cout << ans << endl;
	return 0;
}