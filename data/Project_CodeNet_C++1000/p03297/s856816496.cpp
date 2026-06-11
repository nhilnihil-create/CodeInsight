#include "bits/stdc++.h"

using namespace std;

void solve()
{
	int T;
	cin >> T;
	while(T--)
	{
		long A, B, C, D;
		cin >> A >> B >> C >> D;
		if (A < B || D < B)
		{
			cout << "No" << endl;
			continue;
		}
		long g = __gcd(B, D);
		A = (C+g-A%g)/g*g+A%g;
		//cout << A << ' ';
		cout << (A >= B ? "Yes" : "No") << endl;
	}
}

int main(void)
{
	solve();
	//cout << "yui(*-v・)yui" << endl;
	return 0;
}
