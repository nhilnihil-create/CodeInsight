#include "bits/stdc++.h"
using namespace std;

int main() {

	int64_t A, B, C, X, Y;
	cin >> A >> B >> C >> X >> Y;

	int64_t ans = A*X+B*Y+C*2*(X+Y);

		for (int i = 0;i <= X;i++) {
			if (Y - X + i > 0)
				ans = min(ans, A * i + B * (Y - X + i) + C * 2 * (X - i));

			else
				ans = min(ans, A * i + C * 2 * (X - i));
		}
	

		for (int i = 0;i <= Y;i++) {
			if (X - Y + i > 0)
				ans = min(ans, A * (X - Y + i) + B * i + C * 2 * (Y - i));

			else
				ans = min(ans, B * i + C * 2 * (Y - i));
		}

	cout << ans;


	
}