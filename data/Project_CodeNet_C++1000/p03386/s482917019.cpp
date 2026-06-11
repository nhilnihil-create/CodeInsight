#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i,n) for(int i = 0; i < n; i++)

bool isSquare(int n) {
	int p = sqrt(n);
	if (p * p == n) return true;
	else return false;
}

int main() {
	int a, b, k;
	cin >> a >> b >> k;
	for (int i = a; i <= b; i++) {
		if (i <= a + k - 1 || b - k + 1 <= i) cout << i << endl;
	}
	return 0;
}