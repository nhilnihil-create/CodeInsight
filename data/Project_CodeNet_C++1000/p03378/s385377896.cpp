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

	int N, M, X;
	vector<int> A;

	cin >> N >> M >> X;
	for(int i=1; i<=M; i++){
		int a;
		cin >> a;
		A.push_back(a);
	}

	int c1 = 0, c2 = 0;
	for(int i=0; i<M; i++){
		if(A[i] < X){
			c1++;
		}
		if(A[i] > X){
			c2++;
		}
	}
	int c = min(c1, c2);
	printf("%d\n",c);
	return 0;
}