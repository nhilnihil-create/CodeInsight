#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	for (int n = 1;n<10;++n) {
		if (111*n>=N) {
			cout << 111*n<<endl;
			return 0;
		}
	}
	
	return 0;
}