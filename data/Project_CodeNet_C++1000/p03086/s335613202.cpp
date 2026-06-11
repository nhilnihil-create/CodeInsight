#include <iostream>

using namespace std;

int dat[401];

bool isACGT(char c) {
	return c == 'A' || c == 'G' || c == 'C' || c == 'T';
}

int main() {
	string s;
	cin >> s;
	int l = s.length();
	int maxlen = 0;
	for (int i = 0; i < l; i++){
		int len = 0;
		while (isACGT(s[i])) {
			i++;
			len++;
			if (i >= l)break;
		}
		if (len > maxlen)maxlen = len;
	}
	cout << maxlen << endl;
}