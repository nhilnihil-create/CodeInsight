#include <iostream>
#include <algorithm>
#include <string>
#include <limits.h>

using namespace std;

int main()
{
    
	int n, a, b;
	cin >> n >> a >> b;

	if ((a ^ b) & 1) {
		cout << "Borys" << endl;
	}
	else {
		cout << "Alice" << endl;
	}


	return 0;

}


