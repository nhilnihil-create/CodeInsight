#include <iostream>
#include <string>
using namespace std;
int main(){
	int m = 700;
	string S;
	cin >> S;
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == 'o') {
			m += 100;
		}
		else {
			m += 0;
		}
	}
	cout << m << endl;
}