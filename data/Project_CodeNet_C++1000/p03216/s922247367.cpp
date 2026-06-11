//g++ -Wall -Werror -O2 -std=c++11 main.cpp -o main && main.exe < in.txt
#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define ll long long

int main() {
	ios::sync_with_stdio(false);
	int N, Q;
	string S;
	cin >> N >> S >> Q;
	for (int i = 0; i < Q; i++) {
		int k;
		cin >> k;

		ll a = 0;
		ll b = 0;
		ll m = 0;
		ll ans = 0;
		for (int j = 0; j < N; j++) {
			if (S[j] == 'D') {
				a++;
			} else if (S[j] == 'M') {
				b += a;
				m++;
			} else if (S[j] == 'C') {
				ans += b;
			}

			if (j >= k - 1) {
				if (S[j-k+1] == 'D') {
					a--;
					b -= m;
				} else if (S[j-k+1] == 'M') {
					m--;
				}
			}
		}
		cout << ans << endl;
	}

    return 0;
}
