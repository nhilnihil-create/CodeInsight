#include <iostream>
#include <string>
using namespace std;

int N;
string str0, str1;

int MIN, MAX;

int main(void) {

	cin >> N;
	int pos = (N + 1) / 2;
	if (pos % 2 == 0) { pos--;
	}
	cout << 0 << endl;
	cin >> str0; if (str0 == "Vacant") { return 0; }

	cout << pos<< endl;
	cin >> str1; if (str1 == "Vacant") { return 0; }

	if (str0 == str1) { MIN = 0; MAX = pos; }
	else { MIN = pos; MAX = N; str0 = str1; }

	for(int i=1;i<=20;i++){
		int med = (MIN + MAX) / 2;
		if ((med - MIN) % 2 == 0) { med--; }
		cout << med << endl;
		string tmp;
		cin >> tmp; if (tmp == "Vacant") { return 0; }

		if (str0 == tmp) { MAX = med; str1 = tmp; }
		else { MIN = med; str0 = tmp; }
	}


	return 0;
}