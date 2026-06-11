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

	int D;
	cin >> D;

	if(D == 25){
		printf("Christmas\n");
	}
	else if(D == 24){
		printf("Christmas Eve\n");
	}
	else if(D == 23){
		printf("Christmas Eve Eve\n");
	}
	else if(D == 22){
		printf("Christmas Eve Eve Eve\n");
	}
	return 0;
}

