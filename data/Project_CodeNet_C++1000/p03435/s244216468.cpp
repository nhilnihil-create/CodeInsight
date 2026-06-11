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

long long N, M;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int c[5][5] = {0};
	for(int i=1; i<=3; i++){
		for(int j=1; j<=3; j++){
			cin >> c[i][j];
		}
	}
	int ans = 0;
	int u, v, w, x, y, z;
	u = c[1][2] - c[1][1];
	v = c[2][2] - c[2][1];
	w = c[3][2] - c[3][1];
	x = c[1][3] - c[1][1];
	y = c[2][3] - c[2][1];
	z = c[3][3] - c[3][1];

	if(u == v && v == w && x == y && y == z){
		ans = 1;
	}
	if(ans == 1){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}