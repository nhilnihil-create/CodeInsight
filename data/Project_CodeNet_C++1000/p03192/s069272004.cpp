#include <iostream>
using namespace std;

int main() {
	int n, two = 0;
	cin >> n;
	while (n){
	    if (n%10 == 2)two++;
	    n = n / 10;
	}
	cout << two << endl;
	return 0;
}
