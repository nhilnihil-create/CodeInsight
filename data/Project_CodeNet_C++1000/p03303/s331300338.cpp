#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(void) {
	std::string str; cin >> str;
	int a; cin >> a;
	for (int i = 0; i < str.length(); i += a) {
		cout << str[i];
	}
	cout << endl;
	return 0;
}