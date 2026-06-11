#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>


using namespace std;
using ll = long long;

template<typename T> void print(T t) { cout << t << endl; }

int main() {
	int N, X;
	cin >> N;
	vector<int> xs(N+1);
	for (auto& x : xs)  cin >> x;
	sort(xs.begin(), xs.end());
	int D = xs[1] - xs[0];
	for (int i = 1; i < N; i++) {
		D = gcd(D, xs[i + 1] - xs[i]);
	}
	print(D);
}