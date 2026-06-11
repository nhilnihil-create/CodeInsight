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

	int N, A, B;

	cin >> N;
	if(N == 1){
		printf("Hello World\n");
		return 0;
	}
	else if(N == 2){
		cin >> A;
		cin >> B;
		printf("%d\n", A+B);
		return 0;
	}
	return 0;
}