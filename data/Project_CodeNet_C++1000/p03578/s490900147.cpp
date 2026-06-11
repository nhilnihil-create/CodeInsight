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
	map<LL, int> D;
	for(int i=0; i<N; i++){
		LL d; cin >> d;
		if(D.count(d) == 0){
			D[d] = 1;
		}
		else{
			D[d]++;
		}
	}
	LL M; cin >> M;
	vector<LL> T;
	for(int i=0; i<M; i++){
		LL t; cin >> t;
		if(D.count(t) !=0 && D[t] > 0){
			D[t]--;
		}
		else{
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	return 0;
}