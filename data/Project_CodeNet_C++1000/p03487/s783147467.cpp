#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main (void) {
	int arr[100001];
	int size, 
		rem, coun, res;

	cin >> size;
	for (int it = 0; it < size; ++it) cin >> arr[it];

	sort(arr, arr + size);

	rem = arr[0];
	coun = 1;
	res = 0;
	for (int it = 1; it < size; ++it) {
		if (arr[it] != rem) {
			if (coun - rem >= 0) res += coun - rem;
			else res += coun;
			rem = arr[it];
			coun = 1;
		} else ++coun;
	}
	if (coun - rem >= 0) res += coun - arr[size - 1];
	else res += coun;

	cout << res << endl;

	return 0;
}
