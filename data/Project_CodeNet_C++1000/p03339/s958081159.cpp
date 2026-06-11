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
	int N;
	string S;
	
	cin >> N;
	cin >> S;

	int W[300000+2] = {0}; //W[i] = 1 .. i-1で西を向いている人の数
	int E[300000+2] = {0}; //E[i] = i+1, ... ,Nの中で東を向いている人の数


	W[0] = 0, W[1] = 0;
	for(int i=0; i<S.size(); i++){
		if(S[i] == 'W'){
			W[i+2] = W[i+1] + 1;
		}
		else{
			W[i+2] = W[i+1];
		}
	}

	E[N] = 0, E[N+1] = 0;
	for(int i=S.size()-1; i>=0; i--){
		if(S[i] == 'E'){
			E[i] = E[i+1] + 1;
		}
		else{
			E[i] = E[i+1];
		}
	}

	int ans = 1<<30;
	for(int i=1; i<=N; i++){
		int v = W[i] + E[i];
		if( ans > v ){
			ans = v;
		}
	}
	printf("%d\n", ans);
	return 0;
}