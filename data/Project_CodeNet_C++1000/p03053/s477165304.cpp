#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#include <functional>
#include <queue>

using namespace std;
typedef long long ll;

int G[1000][1000];
int Horizontal[1000][1000];
int Vertical[1000][1000];
int HV[1000][1000];

int main()
{
	int H, W;
	
	cin >> H >> W;
	for(int i = 0; i < H; i++){
		char s[1001];
		cin >> s;
		for(int j = 0; j < W; j++){
			G[i][j] = s[j] == '#' ? 1 : 0;
		}
	}
	
	// 横移動の最短
	for(int i = 0; i < H; i++){
		int temp = 9999;
		for(int j = 0; j < W; j++){
			if(G[i][j] == 1) { temp = 0;}
			Horizontal[i][j] = temp;
			temp++;
		}
		for(int j = W-1; j >= 0; j--){
			if(G[i][j] == 1) { temp = 0;}
			if(Horizontal[i][j] > temp){ Horizontal[i][j] = temp; };
			temp++;
		}
	}
	
	// 縦移動の最短
	for(int j = 0; j < W; j++){
		int temp = 9999;
		for(int i = 0; i < H; i++){
			if(G[i][j] == 1) { temp = 0;}
			Vertical[i][j] = temp;
			temp++;
		}
		for(int i = H-1; i >= 0; i--){
			if(G[i][j] == 1) { temp = 0;}
			if(Vertical[i][j] > temp){ Vertical[i][j] = temp; };
			temp++;
		}
	}
	
	int ans = 0;
	
	// 縦、横合わせた最短
	for(int i = 0; i < H; i++){
		int min__ = 0;
		int temp = Horizontal[i][0];
		for(int j = 0; j < W; j++){
			int m = min(Vertical[i][j] , Horizontal[i][j]);
			temp = min(m, temp + 1);
			HV[i][j] = temp;
		}
		
		for(int j = W-1; j >= 0; j--){
			int m = min(Vertical[i][j] , Horizontal[i][j]);
			temp = min(m, temp + 1);
			if (HV[i][j] > temp) { HV[i][j] = temp; }
		}
	}
	
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			if(ans < HV[i][j]){ ans = HV[i][j]; }
		}
	}
	
	cout << ans << endl;
	
	return 0;
}
