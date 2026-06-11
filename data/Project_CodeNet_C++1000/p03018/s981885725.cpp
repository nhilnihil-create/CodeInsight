#include <iostream>
using namespace std;

int main() {
	string s;
	cin >> s;
	int Anum = 0;
	int state = 0;
	long long ans = 0;
	for (char c : s) {
		if (state == 0 && c == 'A') {
			Anum = 1;
			state = 1;
		}
		else if (state == 1) {
			switch (c) {
			case 'A':
				Anum++;
				break;
			case 'B':
				state = 2;
				break;
			default:
				Anum = 0;
				state = 0;
			}
		}
		else if (state == 2) {
			switch (c) {
			case 'A':
				Anum = 1;
				state = 1;
				break;
			case 'C':
				ans+=Anum;
				state = 1;
				break;
			default:
				Anum = 0;
				state = 0;
			}
		}
	}
	cout << ans << endl;
}