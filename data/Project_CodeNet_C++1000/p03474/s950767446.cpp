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

int A, B;
string S;
int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> A >> B;
	cin >> S;

	int match = 1;
	for(int i=0; i<A; i++){
		if(S[i] == '-'){
			match = 0;
			break;
		}
	}
	if(match == 0 || S[A] != '-'){
		printf("No\n");
		return 0;
	}
	for(int i=0; i<B; i++){
		if(S[A+1+i] == '-'){
			match = 0;
			break;
		}
	}
	if(match == 0){
		printf("No\n");
		return 0;
	}
	printf("Yes\n");
	return 0;
}