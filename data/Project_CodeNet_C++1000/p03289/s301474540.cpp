#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

// ����̕�����𐔂���֐�
size_t count(const string& str, const string& sub, const size_t ini = 0, const size_t fin = string::npos) {
	size_t pos = str.find(sub, ini);
	size_t cnt = 0;
	while (pos < fin) {
		cnt += 1;
		pos = str.find(sub, pos + sub.length());
	}
	return cnt;
}

int main() {

	string S;
	cin >> S;

	string ALP = "ABDEFGHIJKLMNOPQRSTUVWXYZ";

	bool jdg = true;
	string str;
	size_t cnt;
	if ("A" == S.substr(0, 1)) {
		str = S.substr(2, S.length() - 3);
		cnt = count(str, "C");
		if (cnt != 1) {
			jdg = false;
		}
		else {
			str = S.substr(1, S.length() - 1);
			for (int i = 0; i < str.length(); i++) {
				if (string::npos != ALP.find(str.substr(i, 1))) {
					jdg = false;
					break;
				}
			}
		}
	}
	else {
		jdg = false;
	}

	if (jdg == true) {
		cout << "AC" << endl;
	}
	else {
		cout << "WA" << endl;
	}

	return 0;
}

