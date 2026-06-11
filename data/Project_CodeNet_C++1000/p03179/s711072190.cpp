#include <iostream>

using namespace std;

typedef long long ll;
ll mod = 1e9 + 7;

int main(int argc, char *argv[])
{
	int N;
	string s;
	ll from[3005], to[3005];
	ll S[3005];

	cin >> N >> s;

	for (int i = 0; i < N; i++) {
		from[i] = 1;
	}

	for (int i = 0; i < N - 1; i++) {
		for (int i = 0; i < N; i++) {
			to[i] = 0;
		}
		for (int x = 0; x < N + 1; x++) {
			S[x] = ((x ? S[x - 1] : 0) + from[x]) % mod;
		}
		for (int x = 0; x < N - 1 - i; x++) {
			if (s[i] == '>') {
				to[x] = (S[N] + mod - S[x]) % mod;
			} else {
				to[x] = S[x];
			}
		}
		swap(from, to);
	}

	cout << from[0] << endl;

	return 0;
}