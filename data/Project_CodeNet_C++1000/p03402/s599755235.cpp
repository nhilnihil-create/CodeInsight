#include<math.h>
#include<map>
#include<iostream>
#include <algorithm>
#include <string>
#include<vector>
#include<array>
#include<tuple>
#include<queue>
#include<stack>
#include<iomanip>
#include<bitset>
//AtCoderC++.cpp

using namespace std;

vector<int> _prime;
vector<int> build_prime_table(int max) {
	vector<int> table = vector<int>(max + 1, -1);
	table[0] = 0;
	table[1] = 0;
	table[2] = 1;
	for (int i = 3; i <= max; i++) {
		if (i % 2 == 0) { table[i] = 0; continue; }
		if (table[i] != -1)continue;
		table[i] = 1;
		for (int j = i + i; j <= max; j += i) {
			table[j] = 0;
		}
	}
	return table;
}

inline int ceileing(int a, int b) {
	return a % b == 0 ? a / b : a / b + 1;
}


vector<long long> comb = vector<long long>(100 * 100, -1);

long long combination(long long n, long long r) {
	if (n == 1 || n == 0)return 1;
	if (n == r)	return 1;
	else if (r == 0)return 1;
	else if (r == 1)return n;
	else if (comb[100 * (n - 1) + (r - 1)] != -1) return comb[100 * (n - 1) + (r - 1)];
	else {
		auto res = combination(n - 1, r - 1) + combination(n - 1, r);
		comb[100 * (n - 1) + (r - 1)] = res;
		return res;
	}
}


int main() {
	int A, B; cin >> A >> B;
	auto is_white = vector<bool>(100 * 100);
	for (size_t i = 0; i < 100; i++) {
		for (size_t j = 0; j < 100; j++) {
			is_white[i * 100 + j] = j >= 50;
		}
	}
	--A; --B;
	//左半分を黒の領地にして、欲しい数だけ白を打つ。
	//黒を分割せずに白だけを増やす。
	/*
	.#.#.#.#.#.#.#.#
	################
	.#.#.#.#.#.#.#.#
	################
	*/
	//(HW)÷4は稼げる。W=50 H=100 -> 5000/4>500
	int i = 0; int j = 0;
	while (A > 0) {
		is_white[i * 100 + j] = true;
		--A;
		j += 2;
		if (j >= 50) {
			j = 0;
			i += 2;
		}
	}
	//黒について同様
	i = 0; j = 51;
	while (B > 0) {
		is_white[i * 100 + j] = false;
		--B;
		j += 2;
		if (j >= 100) {
			j = 51;
			i += 2;
		}
	}

	cout << 100 << " " << 100 << endl;
	for (size_t i = 0; i < 100; i++) {
		for (size_t j = 0; j < 100; j++) {
			cout << (is_white[i * 100 + j] ? '.' : '#');
		}
		cout << endl;
	}
}