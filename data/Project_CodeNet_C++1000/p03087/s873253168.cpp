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

	int N, Q;
	string S;
	long long AC[100002] = {0};

	
	cin >> N >> Q;
	cin >> S;
	const char* s = S.c_str();
	// N = strlen(s)
	AC[0] = 0;
	for(int i=0; i < N - 1; i++){
		if(strncmp(s+i, "AC", 2) == 0){
			AC[i + 1] = AC[i];
			AC[i + 2] = AC[i + 1] + 1;
			i++;
		}
		else{
			AC[i + 1] = AC[i];
			if(i == N - 2){
				AC[N] = AC[N - 1];
				break;
			}
		}
	}
	if(strncmp(s+N-2, "AC", 2) != 0){
		AC[N] = AC[N-1];
	}

	for(int i = 1; i <= Q; i++){
		int l, r;
		cin >> l >> r;
		long long ans;
		ans = AC[r] - AC[l - 1];
		if(AC[l] != AC[l - 1]){
			ans--;
		}
		cout << ans << endl ;
	}
	return 0;
}