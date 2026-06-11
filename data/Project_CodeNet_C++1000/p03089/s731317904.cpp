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
using Graph = vector<vector<int>>;

typedef long long LL;
static LL INF = (1LL<<62);


LL S;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	LL N;
	vector<LL> B;
	vector<LL> A;

	cin >> N;
	for(int i=0; i<N; i++){
		LL b;
		cin >> b;
		B.push_back(b);
	}
	
	while(B.size()>0){
		int found = 0;
		for(int j=B.size()-1; j>=0; j--){
			if(B[j] == j+1){
				found = 1;
				A.push_back(B[j]);
				B.erase(B.begin() + j);
				break;
			}
		}
		if(found == 0){
			break;
		}
	}

	if(B.size() == 0){
		for(int i=A.size()-1; i>=0; i--){
			printf("%lld\n", A[i]);
		}
	}
	else{
		printf("-1\n");
	}
	return 0;
}