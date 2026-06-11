#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string>
#include <vector>
#include <math.h>
#include <queue>
#include <deque>
#include <stack>
#include <map>
const int MOD = 1e9+7;
#define PI 3.14159265359
typedef long long ll;
using namespace std;

char grid[52][52];

bool is_ok(int x, int y){
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	for (int i = 0; i < 4; i++){
		if (grid[x+dx[i]][y+dy[i]] == '#') return true;
	}
	return false; 
}

int main(){
	int h, w;
	cin >> h >> w;
	for (int i = 1; i <= h; i++){
		for (int j = 1; j <= w; j++){
			cin >> grid[i][j];
		}
	}

	for (int i = 1; i <= h; i++){
		for (int j = 1; j<= w; j++){
			if (grid[i][j] == '#'){
				if (!is_ok(i, j)){
					cout << "No" << endl;
					return 0;
				}
			}
		}
	}
	cout << "Yes" << endl;
	return 0;
}