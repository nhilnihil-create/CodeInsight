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
typedef long long LL;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	cin >> S;

	int near = 999;
	int ans = 0;
	for(int i=0; i<S.size()-2; i++){
		char c[4] = {0};
		for(int j=0; j<3; j++){
			c[j] = S[i+j];
		}
		int d = atoi(c);
		if(abs(d - 753) < near){
			near = abs(d - 753);
			ans = d;
		}
	}
	printf("%d\n", near);
	return 0;
}