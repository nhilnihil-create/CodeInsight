#include<bits/stdc++.h>
using namespace std;

int H, W;

const int di[] = {1, -1, 0, 0};
const int dj[] = {0, 0, 1, -1};

int main(void){
	cin >> H >> W;
	vector<vector<char>> m(H, vector<char>(W));
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			cin >> m[i][j];
		}
	}
	for(int i = 0; i < H; i++){
		for(int j = 0; j < W; j++){
			if(m[i][j] == '#'){
				bool ans = false;
				for(int k = 0; k < 4; k++){
					int ni, nj;
					ni = i+di[k];
					nj = j+dj[k];
					if(ni < 0 || nj < 0 || ni >= H || nj >= W) continue;
					if(m[ni][nj] == '#'){
						ans = false;
						break;
					}
					ans = true;
				}
				if(ans){
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}
