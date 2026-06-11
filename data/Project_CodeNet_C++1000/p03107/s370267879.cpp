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
	cin.tie(0);
	ios::sync_with_stdio(false);

	string S;
	int N;
	cin >> S;
	const char *s = S.c_str();
	N = strlen(s);

	int ans = 0;
	for(int i=0; i<N; i++){
		if(s[i] == '0')
			ans += 1;
		else
			ans -= 1;
	}
	cout << (N - abs(ans)) << endl ;
	return 0;
}
