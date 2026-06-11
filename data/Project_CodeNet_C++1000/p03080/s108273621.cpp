
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

int main() {

	int n;
	string s;
	cin >> n >> s;

	if(count(s.begin(), s.end(), 'R') > count(s.begin(), s.end(), 'B')){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}

	return 0;
}
