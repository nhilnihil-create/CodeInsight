#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int n1, n2, n3, n4;
	cin >> n1 >> n2 >> n3 >> n4;

	bool f1 = false;
	bool f2 = false;
	bool f3 = false;
	bool f4 = false;

	if (n1 == 1 || n2 == 1 || n3 == 1 || n4 == 1) {
		f1 = true;
	}

	if (n1 == 9 || n2 == 9 || n3 == 9 || n4 == 9) {
		f2 = true;
	}

	if (n1 == 7 || n2 == 7 || n3 == 7 || n4 == 7) {
		f3 = true;
	}

	if (n1 == 4 || n2 == 4 || n3 == 4 || n4 == 4) {
		f4 = true;
	}

	if (f1 && f2 && f3 && f4) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}


}
