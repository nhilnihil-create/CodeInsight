#include <iostream>
using namespace std;

int main(){
	int t, a, b;

	cin >> t >> a >> b;

	t = t*a;
	if (t > b){
		t = b;
	}

	cout << t << endl;
}