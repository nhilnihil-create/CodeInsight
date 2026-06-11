#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int A, B;
	cin >> A >> B;

	int n = A * B;

	if (n % 2 == 1) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}

}
