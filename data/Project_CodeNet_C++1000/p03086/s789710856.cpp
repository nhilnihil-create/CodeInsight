#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

void b_ATCoder(void) {
	string s;
	cin >> s;

	int cnt = 0;
	int max_length = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] != 'A' && s[i] != 'C' && s[i] != 'G' && s[i] != 'T') {
			max_length = max(max_length, cnt);
			cnt = 0;
		}
		else cnt++;
	}

	max_length = max(max_length, cnt);

	cout << max_length << endl;
}

int main()
{
    b_ATCoder();

    return 0;
}
