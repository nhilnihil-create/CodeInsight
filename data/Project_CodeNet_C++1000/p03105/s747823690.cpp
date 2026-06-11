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

	int n = B / A;

	if (n <= C) {
		cout << n << endl;
	}
	else {
		cout << C << endl;
	}
	
}