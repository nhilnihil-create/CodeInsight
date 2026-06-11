#include<iostream>
#include<string.h>
using namespace std;
int sum_digits(string a) {
	unsigned int ret = 0;
	for (int i = 0; i < a.size(); i++) {
		ret += a.at(i) - '0';
	}
	//cout << "fx=" << ret << endl;
	return ret;
}
int ati(string a) {
	unsigned int ret = 0;
	for (int i = 0; i < a.size(); i++) {
		ret *= 10;
		ret += a.at(i)-'0';
	}
	//cout << "x=" << ret << endl;
	return ret;
}
int main() {
	string sx;
	unsigned int x;
	unsigned int fx;
	cin >> sx;
	fx = sum_digits(sx);
	x = ati(sx);
	switch(x % fx) {
		case 0:
			cout << "Yes" << endl;
			break;
		default:
			cout << "No" << endl;
			break;
	}

}