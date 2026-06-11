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

	string S;
	cin >> S;

	int YYYY = atoi(S.substr(0, 4).c_str());
	int MM = atoi(S.substr(5, 2).c_str());
	int DD = atoi(S.substr(8, 2).c_str());

	if(YYYY <= 2018){
		printf("Heisei\n");
	}
	else if(YYYY == 2019 && MM <= 4){
		printf("Heisei\n");
	}
	else{
		printf("TBD\n");
	}
	return 0;
}
