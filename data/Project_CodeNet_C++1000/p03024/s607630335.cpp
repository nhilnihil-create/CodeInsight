#include<iostream>
#include<string>
using namespace std;
 
int main() {
	string buff;
	getline(cin, buff);
	int win = 0;
	for (int i = 0; i < buff.length(); ++i) {
		if (buff[i] == 'o') {
			++win;
		}
	}
	cout << (win + (15 - buff.length()) >= 8 ? "YES" : "NO") << endl;
}