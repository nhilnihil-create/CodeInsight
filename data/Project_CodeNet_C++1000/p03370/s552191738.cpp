#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>

#include <climits>

using namespace std;

int main()

{
	int n, x;
	
	cin >> n >> x;

	vector<int> m(n);

	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}

	sort(m.begin(), m.end());

	int sum = 0;
	int count = 0;
	for (int i = 0; i < n; i++) {
		sum = sum + m[i];
		count++;
	}

	int sumsum = x - sum;

	if (sumsum > 0) {
			count=count+sumsum/m[0];
	}

	cout << count << endl;

	return 0;

}