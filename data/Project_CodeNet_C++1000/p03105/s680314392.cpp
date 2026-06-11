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

	if (B >= A * C) {
		cout << C << endl;
	}
	else {
		cout << B / A << endl;
	}

}
