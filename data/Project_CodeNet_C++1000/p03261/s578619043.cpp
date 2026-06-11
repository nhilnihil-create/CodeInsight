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

int main() {
	int n;
	cin >> n;
	string ans = "Yes";
	vector<string> w(n);
	set<string> words;
	rep(i, n) {
		string s;
		cin >> s;
		if (words.count(s)) ans = "No";
		words.insert(s);
		w[i] = s;
	}
	rep(i, n - 1) {
		string now = w[i];
		string next = w[i + 1];
		if (now[now.size()-1] != next[0]) ans = "No";
	}
	cout << ans << endl;
	return 0;
}