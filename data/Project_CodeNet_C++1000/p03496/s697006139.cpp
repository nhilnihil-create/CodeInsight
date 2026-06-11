//#pragma warning(disable:4996)
#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <limits.h>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <bitset>
#include <cassert>
#include <random>
#include <functional>
#include <stack>
#include <iomanip>
#include <cassert>
//#include <boost/multiprecision/cpp_int.hpp>
#include <complex>
#include <cstdio>
#include <list>
#include <bitset>
//#include <stdio.h>

//< in.txt > out.txt
using namespace std;
//std::ios::sync_with_stdio(false);
//std::cin.tie(0);
const long long MOD = 1e9 + 7;
const long long INF = 1e15;
typedef long long LL;
typedef long double LD;
//typedef boost::multiprecision::cpp_int bigint;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PI;
typedef pair<LD, LL> pdl;
typedef pair<LD, LD> pdd;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
typedef vector<int> VI;
typedef vector<vector<int>> VVI;
typedef unsigned long long ULL;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	int N;
	cin >> N;
	VI A(N);
	bool negflag = false;
	for (int n = 0; n < N; n++) {
		cin >> A[n];
		if (A[n] < 0)negflag = true;
	}
	if (!negflag) {
		cout << N - 1 << "\n";
		for (int n = 1; n < N; n++)cout << n << " " << n + 1 << "\n";
		return 0;
	}
	int mi = 0, ma = 0;
	for (int n = 1; n < N; n++) {
		if (A[mi] > A[n])mi = n;
		if (A[ma] < A[n])ma = n;
	}
	cout << 2 * N - 2 << "\n";
	if (A[ma] > -A[mi]) {
		for (int n = 0; n < N; n++) {
			if (n == ma)continue;
			cout << ma + 1 << " " << n + 1 << "\n";
		}
		for (int n = 1; n < N; n++) {
			cout << n << " " << n + 1 << "\n";
		}
	}
	else {
		for (int n = 0; n < N; n++) {
			if (n == mi)continue;
			cout << mi + 1 << " " << n + 1 << "\n";
		}
		for (int n = N; n >= 2; n--) {
			cout << n << " " << n - 1 << "\n";
		}
	}
	return 0;
}
