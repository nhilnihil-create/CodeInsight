#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

void b_cut_and_count(void) {
	string s;
	int n;

	cin >> n >> s;

	int max = 0;

	for (int i = 0; i < n; i++) {
		int l[27] = { 0 };
		int r[27] = { 0 };
		for (int j = 0; j < n; j++) {
			if (i <= j) l[s[j] - 'a']++;
			else        r[s[j] - 'a']++;
		}

		int cnt = 0;
		for (int i = 0; i < 27; i++) {
			if (l[i] != 0 && r[i] != 0) cnt++;
		}

		if (cnt > max)max = cnt;
	}

	cout << max << endl;
}

int main()
{
	b_cut_and_count();
    return 0;
}