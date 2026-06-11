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


int main(){

	int n;
	long long x;

	cin >> n >> x;

	vector<long long> arr(n);

	for (int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());

	if (arr[0] > x) {
		cout << 0 << endl;
		return 0;
	}

	int j = 0;
	int count = 0;

	while (j < n) {
		if (x <= 0) break;
		
		x = x - arr[j];

		if (j == n - 1 && x>0 )break;

		if(x>=0)count++;
		
		j++;

	}

	cout << count << endl;

	return 0;
}