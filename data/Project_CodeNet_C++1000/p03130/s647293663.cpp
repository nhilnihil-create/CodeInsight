
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

int main() {

	int s[4] = {};
	rep(i, 3){
		int a, b;
		cin >> a >> b;
		s[a-1]++;
		s[b-1]++;
	}
	sort(s, s+4);
	if(s[0] == 1 && s[1] == 1 && s[2] == 2 && s[3] == 2){
		cout << "YES" << endl;
	}
	else{
		cout << "NO" << endl;
	}

	return 0;
}
