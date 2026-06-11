#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rep1(i, n) for(int i = 1; i <= (n); i++)
#define Would
#define you
#define please

int main() {
	//おまじない
	cin.tie(0);
	ios::sync_with_stdio(false);



	int N, X, x;
	ll a[200001] = {};
	cin >> N >> X;
	rep(i, N) {
		cin >> x;
		a[i + 1] = a[i] + x;
	}

	ll sontoku = 0;
	rep(i, N) {
		ll toku = 1ll * X * i;
		ll sonn = 0;
		if (i > N / 2) {
			int sore = N - i;
			int ookisa = N / sore;
			int kazuA = N % sore;

			sonn += 2ll * a[kazuA];
			rep1(iii, ookisa - 2) {
				sonn += 2ll * a[kazuA + sore * iii];
				if (toku - sonn < 0) break;
			}
		}

		sontoku = max(sontoku, toku - sonn);
	}

	long long kotae = a[N] * 5 + 2ll * N * X - sontoku;
	cout << kotae << "\n";
	Would you please return 0;
}