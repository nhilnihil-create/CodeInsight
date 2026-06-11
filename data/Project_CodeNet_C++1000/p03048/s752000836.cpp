#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<cmath>
#include<numeric>
#include<iomanip>
using namespace std;
using ll =long long;
const int MOD = 1000000007;

//////検証する数,超えられない数////
long long cine(long long a, long long b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
};
//vector型の初期化
void vec_initialize(vector<ll>& a, const ll N) {
	ll c;

	for (int i = 0; i < N; i++) {

		cin >> c;
		a.push_back(c);

	}

};
void vec_pair_initialize(vector<pair<ll, ll>>& a, const ll N) {
	ll c, d;
	for (int i = 0; i < N; i++) {
		cin >> c >> d;
		a.push_back(make_pair(c, d));
	}
};

int main() {
	int R, G, B, N;
	ll cnt=0;
	cin >> R >> G >> B >> N;
	for (int i = 0; i*R <= N; i++) {
		for (int j = 0; j*G+i*R <= N; j++) {
			if ((N - j * G - i * R) % B == 0) {

				cnt++;

			}
		}
	}
	cout << cnt;

}