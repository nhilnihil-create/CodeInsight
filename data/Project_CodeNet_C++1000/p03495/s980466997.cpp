#include <iostream>
#include <stdio.h>

#include <vector>
#include <cctype>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <climits>

using namespace std;


int main(){
	int n, k;
	
	cin >> n >> k;

	vector<int> arr(n);

	vector<int> sss(200001);
	//sss = { 0 };

	for (int i = 0; i < n; i++) cin >> arr[i];

	for (int i = 0; i < n; i++)	sss[arr[i]]++;
	
	int count = 0;

	sort(sss.begin(), sss.end(),greater<>());
	
	int ball=0;
	for (int i = 0; i < 200001; i++) {
		if (sss[i] != 0) count++;
		if (count > k) {
			ball = ball + sss[i];
		}

	}
	
	cout << ball << endl;
	
	return 0;
}