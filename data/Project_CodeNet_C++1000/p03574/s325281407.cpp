#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;


int main()
{
	int h,w;
	cin>>h>>w;
	vector<vector<char>> field(h);
	for(int i = 0; i < h; i++){
		field[i] = vector<char>(w);
		for(int j = 0; j < w; j++){
			cin>>field[i][j];
		}
	}
	int dx[9] = {-1,0,1,-1,0,1,-1,0,1};
	int dy[9] = {-1,-1,-1,0,0,0,1,1,1};
	for(int i = 0; i < h; i++){
		for(int j = 0; j < w; j++){
			if(field[i][j] == '#'){
				cout<<'#';
			}else{
				int ans = 0;
				for(int k = 0; k < 9; k++){
					int nx = j + dx[k];
					int ny = i + dy[k];
					if( 0 <= nx && nx < w && 0 <= ny && ny < h && field[ny][nx] == '#') ans++;
				}
				cout<<ans;
			}
		}
		cout<<endl;
	}
	return 0;
}

