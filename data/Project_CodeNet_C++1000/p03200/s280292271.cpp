#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;
using ll = long long;
template<typename T> void print(T t) {cout << t << endl;}

int main() {
	string S; 
	cin >> S;
	ll ans = 0, prev=0;
	vector<ll> v(S.size());
	for (size_t i = 0; i < S.size(); i++) {
		if (S[i] == 'B') v[i] = ++prev;
		else ans += prev;
	}
	print(ans);
}