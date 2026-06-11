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
#include "string"

using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i,n) for(int i = 0; i < n; i++)

int pow(int p, int k) {
	int ret = 1;
	rep(i, k) ret *= p;
	return ret;
}

int main() {
	int n; cin >> n;
	int seki = 1;
	rep(i, n) {
		int a; cin >> a;
		if (a % 2 == 0) seki *= 2;
	}
	cout << pow(3, n) - seki << endl;
	return 0;
}