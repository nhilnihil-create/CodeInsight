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
	char b;
	cin >> b;
	if (b == 'A') cout << "T" << endl;
	if (b == 'T') cout << "A" << endl;
	if (b == 'C') cout << "G" << endl;
	if (b == 'G') cout << "C" << endl;
	return 0;
}