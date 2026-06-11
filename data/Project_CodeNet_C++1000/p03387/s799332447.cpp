#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <algorithm>

#include <bits/stdc++.h>
#include <cmath>
#include <limits>

using namespace std;

int main(int argc, char* argv[]){
	vector<int> v;
	int A, B, C;
	
	for(int i=0; i<3; i++){
		int d;
		cin >> d;
		v.push_back(d);
	}
	sort(v.begin(), v.end());

	A = v[0], B = v[1], C = v[2];
	int s = B - A;
	int t = C - B;

	int ans = 0;
	if(s % 2 == 0){
		ans = s / 2 + t;
	}
	else{
		ans = 1 + (s + 1)/2 + t;
	}
	printf("%d\n", ans);
	return 0;
}