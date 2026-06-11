#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	int D; cin >> D;
	
	if (D == 25) {
		cout << "Christmas" << endl;	
	}else if (D == 24) {
		cout << "Christmas Eve" << endl;	
	}else if (D == 23) {
		cout << "Christmas Eve Eve" << endl;	
	}else if (D == 22) {
		cout << "Christmas Eve Eve Eve" << endl;	
	}
	return 0;
}
