#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main (void) {
	char w1[101];
	char w2[101];

	char max2 = 0, min1 = 123;

	fill(w1, w1 + 101, 0);
	fill(w2, w2 + 101, 0);
	scanf("%s %s", w1, w2);

	for (int it = 0; it < 101; ++it) {
		if (w1[it] != 0 && w1[it] < min1) min1 = w1[it];
		if (w2[it] > max2) max2 = w2[it];
	}

	if (max2 > min1) cout << "Yes\n";
	else if (strcmp(w2, w1) > 0) cout << "Yes\n";
	else cout << "No\n";

	return 0;
}
