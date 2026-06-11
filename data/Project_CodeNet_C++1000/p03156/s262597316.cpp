#include <algorithm>
#include <cmath>
#include <climits>
#include <functional>
#include <iostream>
#include <queue>
#include <string>
#include <numeric>
#include <vector>
#include <unordered_set>

using namespace std;
using ll = long long;
template<typename T> void print(T t) {cout << t << endl;}


int main() {
	int N, A, B, p;
	cin >> N >> A >> B;
	int count[3] = {}; 
	for (int i = 0; i < N; i++) {
		cin >> p;
		if (p <= A) count[0]++;
		else if (p <= B) count[1]++;
		else count[2]++;
	}
	print(min({ count[0], count[1], count[2] }));
}