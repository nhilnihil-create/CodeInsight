#include <iostream>
using namespace std;



int main(){
	int a, b=0;
	string s;
	cin >> a;
	cin >> s;
	for (int i = 0; i < a; i++) {
		if (s[i] == 'R')b++;
	}
	if (b > a / 2) {
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
return 0;
}
