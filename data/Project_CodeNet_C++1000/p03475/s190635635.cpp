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

int C[502] = {0};
int S[502] = {0};
int F[502] = {0};

long long wt(int i, long long t){
	long long ret;
	if(t <= S[i]){
		ret = S[i] - t;
	}
	else{
		ret = F[i] - ((t % F[i]) % F[i]) ;
		ret = ret % F[i] ;
	}
	return ret;
}

int main(int argc, char* argv[]){
	int N;

	cin >> N;
	for(int i=1; i<=N-1; i++){
		cin >> C[i] >> S[i] >> F[i] ;
	}

	long long t = 0;
	for(int i=1; i<=N; i++){
		t = 0;
		for(int j=i; j<=N-1; j++){
			t += wt(j, t);
			t += C[j];
		}
		cout << t << endl;
	}
	return 0;
}