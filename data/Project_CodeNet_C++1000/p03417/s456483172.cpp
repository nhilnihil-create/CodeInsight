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
	long long N, M;
	cin >> N >> M;

	long long ans = 0;
	if(N == 1){
		if( M == 1){
			ans = 1;
		}
		else if(M == 2){
			ans = 0;
		}
		else{
			ans = M - 2;
		}
	}
	else if(N == 2){
		ans = 0;
	}
	else if(N > 2){
		if( M == 1 ){
			ans = N - 2;
		}
		else if(M == 2){
			ans = 0;
		}
		else{
			ans = (N - 2) * (M - 2);
		}
	}
	printf("%lld\n", ans);
	return 0;
}