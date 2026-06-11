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
long long INF = (1LL<<62);
typedef long long LL;

LL N;
vector<LL> A, B, C;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for(int i=0; i<N; i++){
		LL a;
		cin >> a;
		A.push_back(a);
	}
	for(int i=0; i<N; i++){
		LL b;
		cin >> b;
		B.push_back(b);
	}
	for(int i=0; i<N; i++){
		C.push_back(B[i] - A[i]);
	}
	sort(C.begin(), C.end());
	LL remain = 0;
	for(int i=0; i<N; i++){
		if(C[i] < 0){
			LL c = 0 - C[i];
			remain = c;
			for(int j=i+1; j<N; j++){
				if(C[j] >= 2){
					LL k = min(C[j] / 2, remain);
					C[j] = C[j] - (2*k);
					remain -= k;
					if(remain == 0){
						break;
					}
				}
			}
			if(remain > 0){
				break;
			}
			if(remain == 0){
				C[i] = 0;
			}
		}
	}
	if(remain > 0){
		printf("No\n");
	}
	else{
		printf("Yes\n");
	}
	return 0;
}

