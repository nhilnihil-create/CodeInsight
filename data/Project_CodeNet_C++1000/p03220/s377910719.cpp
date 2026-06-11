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
	int n,t,a;
	cin >> n;
	cin >> t >> a;
	vector<int> arr(n);
 
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
 
	double point = 200001;
	int area = 0;
	for (int i = 0; i < n;i++) {
		//cout << abs(a - (t - arr[i] * 0.006)) << endl;
		if (point > abs(a - (t - arr[i] * 0.006))) {
			point = abs(a - (t - arr[i] * 0.006));
			area = i+1;
		}
	}
 
	cout << area << endl;
 
	return 0;
 
}