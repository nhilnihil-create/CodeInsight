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
	int F[102][12] = {0};
	int P[102][12] = {0};

	cin >> N;

	for(int i=1; i<=N; i++){
		for(int j=0; j<10; j++){
			cin >> F[i][j];
		}
	}
	for(int i=1; i<=N; i++){
		for(int j=0; j<=10; j++){
			cin >> P[i][j];
		}
	}

	long long ans = 0;
	for(int b=1; b < (1<<10); b++){
		long long ptot = 0;
		for(int i=1; i<=N; i++){
			int c = 0;
			for(int j=0; j<10; j++){
				int u = b & (1<<j);
				if(u !=0 && F[i][j] ==1){
					c++;
				}
			}
			ptot += P[i][c];
		}
		if(b==1){
			ans = ptot;
		}
		else if(ans < ptot){
			ans = ptot;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
