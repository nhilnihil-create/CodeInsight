#include<iostream>
#include<stdio.h>
#include<math.h>
#include<vector>
#include<string>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>


using namespace std;

using ll = long long;





int main()
{
	int N;

	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		ll A, B;

		cin >> A >> B;

		ll base = sqrt(A*B);

		ll ans = 0;

		ans += base * 2;

		if (base*base == A*B) { ans--; }

		if (A == B) { ans--; }
		else
		{
			ans--;
			
			ll min = A < B ? A : B;// 4
			ll max = A > B ? A : B;// 11

			ll q = (A*B % (B + 1) == 0) ? (A*B / (B + 1) - 1) : (A*B / (B + 1));// 5のときの８

			if (q == max-1) { ans--; }

			ll p = (A*B % base == 0) ? (A*B / base - 1) : (A*B / base);

			if (p - 1 < base) {
				--ans;
			}
			
		}

		cout << ans << endl;
	}

	return 0;
}