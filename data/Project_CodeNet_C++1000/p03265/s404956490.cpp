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
#define rep(i,n) for(int i = 0; i < n; i++)

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	int x = c - a; int y = d - b;
	printf("%d %d %d %d", c - y, d + x, a - y, b + x);
	return 0;
}