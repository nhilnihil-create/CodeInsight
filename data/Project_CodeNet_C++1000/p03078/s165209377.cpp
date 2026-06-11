#include <iostream>
#include <numeric>
#include <cmath>
#include <limits>
#include <stdio.h>
#include <iomanip>
#include <string> // string, to_string, stoi
#include <vector> // vector
#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound
#include <utility> // pair, make_pair
#include <tuple> // tuple, make_tuple
#include <cstdint> // int64_t, int*_t
#include <cstdio> // printf
#include <map> // map
#include <queue> // queue, priority_queue
#include <set> // set
#include <stack> // stack
#include <deque> // deque
#include <unordered_map> // unordered_map
#include <unordered_set> // unordered_set
#include <bitset> // bitset
#include <cctype> // isupper, islower, isdigit, toupper, tolower
using namespace std;
using ll = long long;
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
ll Max(ll(a), ll(b), ll(c)) {
	return max(max(a, b), c);
}
ll Min(ll(a), ll(b), ll(c)) {
	return min(min(a, b), c);
}




int main() {

	ll X, Y, Z,K;
	cin >> X >> Y >> Z>>K;

	vector<ll> A(X);
	vector<ll> B(Y);
	vector<ll> C(Z);
	vector<ll> AB(max(K,X*Y));
	rep(i, X) {
		cin >> A[i];
	}
	rep(i, Y) {
		cin >> B[i];
	}
	rep(i,Z) {
		cin >> C[i];
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	sort(C.begin(), C.end());
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	reverse(C.begin(), C.end());
	rep(i, X) {
		rep(j, Y) {
			AB[i * Y + j] = A[i] + B[j];
		}
	}
	if (X * Y < K) {
		for (ll i = X * Y; i < K; i++) {
			AB[i] = 0;
		}
	}
	sort(AB.begin(), AB.end());
	reverse(AB.begin(), AB.end());

	vector<ll> ABC(Z*K);
	rep(i, K) {
		rep(j, Z) {
			ABC[i * Z + j] = AB[i] + C[j];
		}
	}
	sort(ABC.begin(), ABC.end());
	reverse(ABC.begin(), ABC.end());
	rep(i, K) {
		cout << ABC[i] << endl;
	}

}