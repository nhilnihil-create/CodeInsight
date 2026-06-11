
#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <functional>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))

using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;
const ll inf = (1LL << 60);
const ll mod = 1000000007;
ll max(ll a, ll b) {
	if (a < b)
		return b;
	else
		return a;

}
ll min(ll a, ll b) {
	if (a < b)
		return a;
	else
		return b;

}
double max(double a, double b) {
	if (a < b) return b;

	return a;
}


ll N;
string S;
ll Q;
ll k[76];
ll sumD[1000005], sumM[1000005], DM[1000005], DMC[1000005];
int main() {
	cin >> N >> S >> Q;
	rep(i, Q) {
		cin >> k[i];
	}

	sumD[0] = (S[0] == 'D') ? 1 : 0;
	sumM[0] = (S[0] == 'M') ? 1 : 0;
	for(int i = 1; i < S.size(); i++){

		if (S[i] == 'D') {
			sumD[i] = sumD[i - 1] + 1;
		}
		else {
			sumD[i] = sumD[i - 1];
		}
		if (S[i] == 'M') {
			sumM[i] = sumM[i - 1] + 1;

		}
		else {
			sumM[i] = sumM[i - 1];
		}

	}

	for (int i = 1; i < S.size(); i++) {
		if (S[i] == 'M') {
			DM[i] = DM[i - 1] + sumD[i];
		}
		else {
			DM[i] = DM[i - 1];
		}
	}
	ll sum = 0, index = 0;
	for (int j = 0; j < Q; j++) {
		rep(i, N) {
			DMC[i] = 0;
		}

		for (int index = 1; index < N; index++) {
			if (S[index] == 'C' && k[j] > index) {
				DMC[index] = DMC[index - 1] + DM[index];
			}
			else if (S[index] == 'C' && k[j] <= index) {
				DMC[index] = DMC[index - 1] + DM[index] - DM[index - k[j]] - sumD[index - k[j]] * (sumM[index] - sumM[index - k[j]]);

			}
			else
				DMC[index] = DMC[index - 1];

		}

		cout << DMC[N - 1] << endl;

	}
	return 0;
}