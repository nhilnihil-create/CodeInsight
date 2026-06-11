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
	int N, K;
	int A[100000+2] = {0};

	cin >> N >> K;
	for(int i=1; i<=N; i++){
		cin >> A[i];
	}

	//A1, ... , ANは 1, 2, ... , Nの並び替え
	//最小は1。最終的な数列は all 1の数列。
	int ind_min = 0;
	for(int i=1; i<=N; i++){
		if(A[i] == 1){
			ind_min = i;
		}
	}

	int ans = (N - 1) / (K - 1);
	if((N - 1) % (K - 1) != 0){
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}