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

	LL N, M, X, Y;
	cin >> N >> M >> X >> Y;

	vector<LL> A, B;
	A.push_back(X);
	for(int i=0; i<N; i++){
		LL a;
		cin >> a;
		A.push_back(a);
	}
	B.push_back(Y);
	for(int i=0; i<M; i++){
		LL b;
		cin >> b;
		B.push_back(b);
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	LL u = A[A.size()-1];
	LL v = B[0];
	if(u < v){
		printf("No War\n");
	}
	else{
		printf("War\n");
	}
	return 0;
}

