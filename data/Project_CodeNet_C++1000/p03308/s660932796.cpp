#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

int main()

{
	int n;
	long long a;
	cin >> n;
	vector<long long> arr(n);
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	sort(arr.begin(), arr.end());

	cout << arr[n - 1] - arr[0] << endl;

	return 0;

}