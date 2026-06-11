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

int x[102] = {0};
int y[102] = {0};
int h[102] = {0};

int main(int argc, char* argv[]){
	int N, CX, CY;

	cin >> N;
	for(int i=1; i<=N; i++){
		cin >> x[i] >> y[i] >> h[i];
	}

	int cx, cy, w;
	int H, HUP, notMatch;
	for(cx= 0;  cx <= 100; cx++){
		for(cy = 0; cy <= 100; cy++){
			notMatch = 0, H = -1, HUP = -1;
			for(int i = 1; i <= N; i++){
				if(h[i] > 0){
					w = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
					if(H == -1){
						H = w;
					}
					else if(H != w){
						notMatch = 1;
						break;
					}
				}
				else if(h[i] == 0){
					w = abs(x[i] - cx) + abs(y[i] - cy);
					if(HUP == -1){
						HUP = w;
					}
					else{
						HUP = min(HUP, w);
					}
					if(H > HUP){
						notMatch = 1;
						break;
					}
				}
			}
			if(notMatch == 0){ break; }
		}
		if(notMatch == 0){ break; }
	}
	printf("%d %d %d\n", cx, cy, H);
	return 0;
}