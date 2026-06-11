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

	LL N; cin >> N;
	string S; cin >> S;
	int ans = 0;
	for(int i=0; i<N-1; i++){
		int u = 0;
		map<char, int> m;
		for(int j=0; j<=i; j++){
			char s = S[j];
			if(m.count(s) == 0){
				m[s] = 1;
			}
		}
		for(int j=i+1; j<N; j++){
			char s = S[j];
			if(m.count(s) !=0 && m[s] == 1){
				m[s]++;
				u++;
			}
		}
		if(ans < u){
			ans = u;
		}
	}
	printf("%d\n", ans);
	return 0;
}
