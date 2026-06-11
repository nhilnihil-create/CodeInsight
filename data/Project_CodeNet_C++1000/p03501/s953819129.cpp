#include <iostream>
using namespace std;

int main() {
	int n, a, b, t;

	cin >> n >> a >> b;

	t = n * a;

	if (t < b) {
		cout << t << endl;
	}

	else if(t == b){
		cout << t << endl;
	}

	else if(t > b){
		cout << b << endl;
	}


}
