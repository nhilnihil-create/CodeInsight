#include <bits/stdc++.h>
using namespace std;

int main() {

	int n, a, b;
	cin >> n >> a >> b;

	int planA = n * a;
	int planB = b;
	if (planA < planB) {
		cout << planA << endl;
	}
	else {
		cout << planB << endl;
	}
}
