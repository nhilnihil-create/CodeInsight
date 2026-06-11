#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int A, B, C;
	cin >> A >> B >> C;

	if (A == B && B == C && C == A) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}
