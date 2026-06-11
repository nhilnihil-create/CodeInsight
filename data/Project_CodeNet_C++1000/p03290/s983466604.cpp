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

#define MAX 10000

int D;
long long G;
int p[10+2] = {0};
int c[10+2] = {0};
long long C[10+2] = {0};

int main(int argc, char* argv[]){
	cin >> D >> G;

	for(int i = 0; i < D; i++){
		cin >> p[i] >> c[i];
		C[i] = (100 * (i+1) * p[i]) + c[i];
	}

	//コンプリートの有無によるビット全探索
	int ans = 100*10;
	for(int b = 0; b < (1<<D); b++){
		long long point = 0;
		int problems = 0;
		for(int i=0; i<D; i++){
			if( b & (1<<i) ){ //コンプリートする100(i+1)点問題
				point += C[i];
				problems += p[i];
			}
		}
		if(point < G){ //このパターンのコンプリートだけでは不足
			for(int i=D-1; i>=0; i--){ //コンプリートしていない高得点のものから解く
				if( !( b & (1<<i) ) ){ 
					for(int j=1; j<=p[i]-1; j++){ //コンプリートではないので、j=p[i]は除外。
						point += 100 * (i+1);
						problems++;
						if(point >= G){
							break;
						}
					}
				}
				if(point >= G){
					break;
				}
			}
		}
		if(point >= G && ans > problems){
			ans = problems;
		}
	}
	cout << ans << endl;
	return 0;
}