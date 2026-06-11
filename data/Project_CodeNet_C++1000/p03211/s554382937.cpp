#include <algorithm>
#include <bitset>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <cctype>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <limits>
#include <map>
#include <memory>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <math.h>
using namespace std;
using ll = long long;
using vl = vector<long long>;
using vll = vector<vector<long long>>;
using vs = vector<string>;
using vc = vector<char>;
using vcc = vector<vector<char>>;
using vm = vector<short>;
using vmm = vector<vector<short>>;
int main() {
	string S;
	cin >> S;
	vector<string>A(S.size() - 2);
	vector<int>C(S.size() - 2);

	for (int i = 0; i < S.size() - 2; i++) {
		A[i] = S.substr(i, 3);
	}
	for (int i = 0; i < S.size() - 2; i++) {
		C[i] = abs(753 - stoi(A[i]));
	}
	sort(C.begin(), C.end());
	cout << C[0] << endl;
}
