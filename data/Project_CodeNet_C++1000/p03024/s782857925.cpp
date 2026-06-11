
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

int main() {

	string s;
	cin >> s;

	if(count(s.begin(), s.end(), 'o') + (15-s.length()) >= 8){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}
