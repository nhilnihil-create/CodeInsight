#include<iostream>
#include<string>
using namespace std;

int main() {
	string akb = "KIHBR";
	int index = 0;
	string buff;
	bool success = false;
	bool beforeA = false;
	getline(cin, buff);
	for (int i = 0; i < buff.length(); ++i) {
		if (buff[i] == akb[index]) {
			beforeA = false;
			++index;
			if (index >= akb.length()) {
				if (buff.length() - 1 - i > 1) {
					break;
				}
				else if (buff.length() - 1 - i == 1) {
					if (buff[i + 1] != 'A') {
						break;
					}
				}
				success = true;
				goto endLoop;
			}
		}
		else if (buff[i] == 'A') {
			if (beforeA) {
				beforeA = false;
				break;
			}
			else {
				switch (index) {
				case 0:
				case 3:
				case 4:
				case 5:
					beforeA = true;
					break;
				default:
					beforeA = false;
					goto endLoop;
					break;
				}
			}
		}
		else {
			beforeA = false;
			break;
		}
	}
endLoop:
	cout << (success ? "YES" : "NO") << endl;
}