
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

int main() {

	string s;
	cin >> s;
	int n;
	cin >> n;

	string ans = "";
	rep(i, s.length()){
		if(i % n == 0){
			ans += s[i];
		}
	}
	cout << ans << endl;

    return 0;
}
