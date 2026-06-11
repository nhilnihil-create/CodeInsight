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
bool Pinching_In(ll a, ll x, ll b) {

	if (a <= x && x <b) {


		return true;
	}
	return false;
}
int main() {
	string S;
	cin >> S;
	string key = "keyence";
	if (S.substr(0, 7) == key) {
		cout << "YES";
		return 0;
	}
	if (S.substr(S.size() - 7, 7)==key ){
		cout << "YES";
		return 0;

	}
	if (S[0] != 'k') {


		cout << "NO";
		return 0;
	}
	for (int i = 0; i < 7; i++) {

		if (S[i] != key[i]) {

			if (S.substr(S.size() - 7 + i, 7 - i) == key.substr(i, 7 - i))
			{

				cout << "YES";
				return 0;

			}else{

				cout << "NO";
				return 0;
			}
		}

	}


}