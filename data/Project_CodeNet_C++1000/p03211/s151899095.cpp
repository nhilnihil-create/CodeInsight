#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_754(void) {
	string s;
	cin >> s;
	int min = 753;

	for (int i = 0; i < (s.size() - 2); i++) {
		int num =stoi(s.substr(i, 3));
		int dif = abs(753 - num);

		if (min > dif) min = dif;
	}

	cout << min << endl;
}

int main()
{
    b_754();

    return 0;
}