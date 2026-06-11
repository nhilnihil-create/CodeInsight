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
	const char *s;
	int sl[100002] = {0}, bl[100002] = {0}, wl[100002] = {0};

	cin >> S;
	s = S.c_str();
	N = strlen(s);
	for(int i=0; i<N; i++){
		char tmp[2] = {0};
		tmp[0] = s[i];
		sl[i] = atoi(tmp);
		bl[i] = i % 2;
		wl[i] = (i+1) % 2;
	}

	int b = 0, w = 0;
	for(int i=0; i<N; i++){
		b += abs(sl[i] - bl[i]);
		w += abs(sl[i] - wl[i]);
	}
	int ans = min(b, w);
	cout << ans << endl;
	return 0;
}