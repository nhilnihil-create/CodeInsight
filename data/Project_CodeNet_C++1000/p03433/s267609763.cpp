#include <iostream>
#include <string.h>
using namespace std;

void a_infinite_coins(void) {
	int n;
	int a;
	cin >> n >> a;
	int hasu = n % 500;
	if (a >= hasu) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}

int main()
{
	a_infinite_coins();
    return 0;
}