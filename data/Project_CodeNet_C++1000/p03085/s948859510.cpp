#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	char b;
	cin >> b;

	if (b == 'A') {
		cout << "T" << endl;
	}
	else if (b == 'T') {
		cout << "A" << endl;
	}
	else if (b == 'G') {
		cout << "C" << endl;
	}
	else if (b == 'C') {
		cout << "G" << endl;
	}
}
