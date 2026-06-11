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

	for (int C = 1; C <= 3; C++) {
		if (A * B * C % 2 == 1) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;

}




