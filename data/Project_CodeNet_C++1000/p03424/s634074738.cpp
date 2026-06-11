#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_hina_arare(void) {
	int n;
	char s[110];
	int flag = 0;
	string judge = "Three";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		if (s[i] == 'P')      flag |= (0x1 << 0);
		else if (s[i] == 'W') flag |= (0x1 << 1);
		else if (s[i] == 'G') flag |= (0x1 << 2);
		else                  flag |= (0x1 << 3);
	}

	if (flag == 0xf) judge = "Four";
	cout << judge << endl;
}

int main()
{
	b_hina_arare();
    return 0;
}