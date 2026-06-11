#include <bits/stdc++.h>
using namespace std;
int main()
{
	int A, B, C;
	cin >> A >> B >> C;
	int D = A + B;

	if (D > C || D == C) {
		cout << "Yes" << endl;
	}

	else if (D < C) {
		cout << "No" << endl;
	}
}
