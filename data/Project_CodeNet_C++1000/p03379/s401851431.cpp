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

long long N;
vector<long long> X;
vector<long long> XS;

int binSearch(long long v){
	int ret = 0;
	int s = 0, e = X.size() - 1;
	int m ;
	while(e - s > 1){
		m = (s + e) / 2;
		if(XS[m] > v){
			e = m;
		}
		else{
			s = m;
		}
	}
	if(XS[s] == v){
		ret = s;
	}
	else if(XS[s + 1] == v){
		ret = s + 1;
	}
	return ret;
}

int main(int argc, char* argv[]){

	cin >> N;
	for(int i=1; i<=N; i++){
		long long v;
		cin >> v;
		X.push_back(v);
		XS.push_back(v);
	}

	sort(XS.begin(), XS.end());

	for(int i=0; i<N; i++){
		long long B;
		//二分探索でX[i]の位置を探す
		int pos = binSearch(X[i]);
		if(pos <= (N/2) - 1){
			B = XS[N/2];
		}
		else{
			B = XS[(N/2) - 1];
		}
		printf("%lld\n", B);
	}
	return 0;
}