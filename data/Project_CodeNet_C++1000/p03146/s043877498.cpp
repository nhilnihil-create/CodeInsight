#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

int b_collats_sub(int n) {
	return (n & 0x1) == 0x1 ? (3 * n + 1) : (n >> 1);
}

void b_collats_problem(void) {
	int s;
	cin >> s;
	int i = 1;
	int ai;
	int before_ai;
	bool m[1000000] = { false };
	while (true) {
		if (i == 1)ai = s;
		else {
			before_ai = ai;
			ai = b_collats_sub(before_ai);
			if (m[ai]) break;	
		}
		m[ai] = true;
		i++;
	}

	cout << i << endl;
}

int main()
{
    b_collats_problem();

    return 0;
}
