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
long long INF = (1LL<<62);
typedef long long LL;

int main(int argc, char* argv[]){
	cin.tie(0);
	ios::sync_with_stdio(false);

	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};

	int H, W; cin >> H >> W;
	vector<vector<int>> V;
	V.assign(H, vector<int>(W, 0));
	for(int i=0; i<H; i++){
		string s; cin >> s;
		for(int j=0; j<W; j++){
			char c = s[j];
			if(c == '.'){
				V[i][j] = 0;
			}
			else{
				V[i][j] = 1;
			}
		}
	}

	int impossilbe = 0;
	for(int i=0; i<H; i++){
		for(int j=0; j<W; j++){
			if(V[i][j] == 1){
				int c = 0;
				for(int k=0; k<4; k++){
					int nx = j+dx[k];
					int ny = i+dy[k];
					if(0 <= ny && ny < H && 0 <= nx && nx <= W){
						if(V[ny][nx] == 1){
							c++;
						}
					}
				}
				if(c < 1){
					impossilbe = 1;
					break;
				}
			}
		}
		if(impossilbe == 1){
			break;
		}
	}
	if(impossilbe == 1){
		printf("No\n");
	}
	else{
		printf("Yes\n");
	}
	return 0;
}
