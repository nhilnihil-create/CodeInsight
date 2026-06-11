#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

int main() { 
	int n;
	cin >> n;
	int p = n;
	int sum = 0;
	while (p > 0) {
		sum += p % 10;
		p = p / 10;
	}
	if (n % sum == 0) {
		cout << "Yes";
	}else {
		cout << "No";
	}
}
