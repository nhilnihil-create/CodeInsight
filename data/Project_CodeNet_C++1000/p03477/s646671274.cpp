#include <iostream>
using namespace std;

int main() {
	int a, b, c, d, l, r;

	cin >> a >> b >> c >> d;

	l = a + b;
	r = c + d;

	if (l > r) {
		cout << "Left" << endl;
	}
	else if (l == r) {
		cout << "Balanced" << endl;
	}else if(l < r){
		cout << "Right" << endl;
	}


}