#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

int main() {

	int A, B;
	cin >> A >> B;

	int ans = A * B;
	
	if (ans % 2 == 0) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
	}

	return 0;
}
