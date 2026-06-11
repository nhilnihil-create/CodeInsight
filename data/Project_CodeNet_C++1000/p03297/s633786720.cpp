#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int T;
long long A, B, C, D;

long long gcd(long long int m, long long int n)
{
	// ユークリッドの方法
	while (m != 0 && n != 0)
	{
		if (m > n) m %= n;
		else       n %= m;
	}
	return max(m, n);
}//gcd

bool is_endless() {
	if (A < B) {
		return false;
	}
	else {
		if (D < B) {
			return false;
		}
		else {
			if (C >= B - 1) {
				return true;
			}
			else {
				long long a = A % B;
				if (a > C) {
					return false;
				}
				else {
					if (D == B) {
						return true;
					}
					else {
						long long g = gcd(B, D);
						long long M = B - g + a % g;
						if (M > C) {
							return false;
						}
						else {
							return true;
						}
					}
				}
			}
		}
	}
}

void solve() {
	string ans;

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> A >> B >> C >> D;
		if (is_endless()) {
			ans = "Yes";
		}
		else {
			ans = "No";
		}
		cout << ans << "\n";
	}

}

int main() {
	solve();
	return 0;
}
