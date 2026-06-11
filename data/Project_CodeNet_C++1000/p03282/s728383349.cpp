#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<list>
#include<bitset>
using namespace std;

int main() {

	string S;
	long long K;

	cin >> S;
	cin >> K;

	int p = 0;

	for (int i = 0; i < K; i++) {
		p = i;
		if (S[i] > '1') {
			break;
		}
	}

	cout << S[p] << endl;

	return 0;
}

