#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

int main() {
	vector<int> a(3), b(3);

	bool flag = true;
	int one = 0, two = 0, three = 0, four = 0;

	for (int i = 0; i < 3; i++) {
		
		cin >> a.at(i) >> b.at(i);
		if (a.at(i) == b.at(i)) {
			flag = false;
			break;
		}
		switch (a.at(i)){
		case 1: one++; if (one > 1) { flag = false; }; break;
		case 2: two++;  if (two > 2) { flag = false; }; break;
		case 3: three++; if (three > 2) { flag = false; }; break;
		case 4:four++; if (four > 2) { flag = false; }; break;
		}

		switch (b.at(i)) {
		case 1: one++; if (one > 1) { flag = false; }; break;
		case 2: two++;  if (two > 2) { flag = false; }; break;
		case 3: three++; if (three > 2) { flag = false; }; break;
		case 4:four++; if (four > 2) { flag = false; }; break;
		}
	}

	if (flag == true) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;
	}

}