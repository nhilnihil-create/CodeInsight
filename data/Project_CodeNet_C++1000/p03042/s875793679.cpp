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

int main() {
	string s;
	cin >> s;
	int a = stoi(s.substr(0, 2));
	int b = stoi(s.substr(2, 2));
	if (1 <= a && a <= 12 && 1 <= b && b <= 12) cout << "AMBIGUOUS" << endl;
	else if (1 <= a && a <= 12 && (b == 0 || 13 <= b)) cout << "MMYY" << endl;
	else if (1 <= b && b <= 12 && (a == 0 || 13 <= a)) cout << "YYMM" << endl;
	else cout << "NA" << endl;
	return 0;
}