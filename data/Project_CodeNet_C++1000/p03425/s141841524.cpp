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

int P[7] = {0};

int main(int argc, char* argv[]){
	int N;

	cin >> N;
	for(int i=1; i<=N; i++){
		string str;
		cin >> str;
		char c = str.at(0);
		if(c == 'M'){ P[0]++; }
		else if(c == 'A'){ P[1]++; }
		else if(c == 'R'){ P[2]++; }
		else if(c == 'C'){ P[3]++; }
		else if(c == 'H'){ P[4]++; }
	}

	long long ans = 0;
	for(int b = 1; b < (1<<5); b++){
		int bitc = 0;
		long long tmp = 1;
		for(int j=0; j<5 && bitc<=3 ; j++){
			if( b & (1<<j) ){
				bitc++;
				tmp = tmp * (long long)P[j];
			}
		}
		if(bitc == 3){
			ans += tmp;
		}
	}
	cout << ans << endl;
	return 0;
}