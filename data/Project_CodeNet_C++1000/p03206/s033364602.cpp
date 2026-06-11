#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int D;
	cin >> D;
	
	if (D==25) {
		cout << "Christmas" << endl;
	}	else if (D==24) {
		cout << "Christmas Eve" << endl;
	} 	else if (D==23) {
		cout << "Christmas Eve Eve" << endl;
	}	else if (D==22) {
		cout << "Christmas Eve Eve Eve" << endl;
	}
	return 0;
}
