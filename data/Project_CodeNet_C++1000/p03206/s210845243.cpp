#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int D;
	cin >> D;
	D = 25 - D;
	string S = "Christmas";
	rep(i, D){
		S += " Eve";
	}
	cout << S << endl;
	return 0;
}
