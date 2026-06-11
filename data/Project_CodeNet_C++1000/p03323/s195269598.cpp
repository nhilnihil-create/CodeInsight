#include<bits/stdc++.h>
#define INF 2000000000
#define MOD 1000000007
#define EPS (1e-10)

using namespace std;

int main(int argc, char *argv[]) {

	int A,B; cin >> A >> B;

	if (max(A, B) > 8) {
		cout << ":(" << endl;	
	}else {
		cout << "Yay!" << endl;	
	}

	return 0;
}
