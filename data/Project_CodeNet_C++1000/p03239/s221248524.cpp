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

long long N, T;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> T;
	vector<long long> C;

	for(int i=0; i<N; i++){
		long long c, t;
		cin >> c >> t;
		if(t <= T){
			C.push_back(c);
		}
	}
	
	if(C.size() == 0){
		printf("TLE\n");
		return 0;
	}

	sort(C.begin(), C.end());
	printf("%lld\n", C[0]);
	return 0;
}