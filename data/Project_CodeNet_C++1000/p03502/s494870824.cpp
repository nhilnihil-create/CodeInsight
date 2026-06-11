#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_harshad_number(void) {
	int n,m;
	int wa = 0;
	string judge = "No";
	cin >> n;
	m = n;
	while (true) {
		wa += (n % 10);
		n /= 10;
		if (n == 0) break;
	}

	if (m % wa == 0) judge = "Yes";

	cout << judge << endl;
}

int main()
{
	b_harshad_number();
    return 0;
}