#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	int N; cin >> N;

	if (N < 1200) {
		cout << "ABC" << endl;
	}else if (N < 2800) {
		cout << "ARC" << endl;
	}else {
		cout << "AGC" << endl;
	}	
	return 0;
}
