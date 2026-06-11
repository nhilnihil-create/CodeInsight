#include <iostream>
#include <string>

using namespace std;

int main(){
	string a;
	cin >> a;
	int b = 700;
	for (int i = 0; i < a.size(); i++) {
	
		if (a[i] == 'o') {
			b+= 100;
		}
	}
	cout << b << endl;
}