
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define rep(i, n) for(int i=0; i<(n); ++i)
#define REP(i, d, n) for(int i=(d); i<(n); ++i)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;

int main() {

	string s;
	cin >> s;

	string t = "";
	rep(i, s.length()){
		t += s[i];
		if(t + "FESTIVAL" == s){
			cout << t << endl;
		}
	}

    return 0;
}




