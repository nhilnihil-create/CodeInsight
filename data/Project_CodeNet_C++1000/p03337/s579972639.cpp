#include <iostream>

using namespace std;

int main(){

	int a,b;

	cin >> a >> b;

	int sum = a + b;
	int mul = a * b;
	int sub = a - b;

	if(sum >= mul && sum >= sub){
		cout << sum << endl;
	}
	else if(mul >= sum && mul >= sub){
		cout << mul << endl;
	}
	else if(sub >= sum && sub >= mul){
		cout << sub << endl;
	}
	else{
		cout << mul << endl;
	}

	return 0;
}