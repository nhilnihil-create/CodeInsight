#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;
int main() {
	vector<int> a(10);
	string s, ans;
	cin >> s;
	if (s == "A")cout << 'T' << endl;
	if (s == "T")cout << 'A' << endl;
	if (s == "G")cout << 'C' << endl;
	if (s == "C")cout << 'G' << endl;
	return 0;
}
