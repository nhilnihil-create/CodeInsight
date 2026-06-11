#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;


int main(int argc, char *argv[]) {

	int A,B,C; cin >> A >> B >> C;

	if (A * C <= B) {
		cout << C << endl;
	}else {
		cout << B / A << endl;	
	}

	return 0;
}
