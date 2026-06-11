
#include <iostream>
#include <numeric>
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
int Max(int(a), int(b), int(c)) {
	return max(max(a, b), c);
}
int Min(int(a), int(b), int(c)) {
	return min(min(a, b), c);
}

int gcd(ll(a), ll(b)) {
	ll c = a;
	while (a % b != 0) {
		c = a % b;
		a = b;
		b = c;
	}
	return b;
}



int main() {
 
	
	ll N,X;
	cin >> N>>X;
	ll an ;
	
	vector<ll> W(N);
	
	for (ll i = 0; i < N; i++) {
		
		cin >> W.at(i);
		
		
	}
	an = W.at(0)-X;
	for (ll i = 0; i < N; i++) {

		an = gcd(an, W.at(i) - X);

	}
	
	
	cout <<abs(an)<< endl;
}