#include <iostream> 
#include <string>
using namespace std;
int main() {
	string topping;
	cin >> topping;

	int P;
	P = 700;

	for (int i = 0; i < 3; i++) {
		if (topping.at(i) == 'o') {
			P += 100;
		}
	}
	cout << P << endl;
}