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
const int INF = 1001001001;

int main() {
	string s, t;
	cin >> s >> t;
	int n = s.size();
	string ans = "No";
	//sをi回回転して得られる文字列nowがtに一致するか調べる
	rep(i, n) {
		//nowにsの末尾i文字を追加する
		string now = s.substr(n-i, i);
		//nowにsの頭n-i文字を追加する
		rep(j, n - i) now += s[j];
		//nowがtと一致しているか判定する
		if (now == t) {
			ans = "Yes";
			break;
		}
	}
	cout << ans << endl;
	return 0;
}