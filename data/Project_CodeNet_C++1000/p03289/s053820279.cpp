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
const double INF = 1001001001;

int main() {
	string s;
	cin >> s;
	int n = s.size();
	string t = s.substr(2, n - 3);
	string ans = "AC";
	//sの先頭の文字が大文字Aか？
	if (s[0] != 'A') ans = "WA";
	//tの中にCがちょうど一つ含まれるか？
	int m = t.size();
	int cnt = 0;
	rep(i, m) {
		if (t[i] == 'C') cnt++;
	}
	if (cnt != 1) ans = "WA";
	//Sのなかに大文字がふたつだけ含まれるか？
	int cnt2 = 0;
	rep(i, n) {
		if (isupper(s[i])) cnt2++;
	}
	if (cnt2 != 2) ans = "WA";
	
	cout << ans << endl;
	return 0;
}