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


int main(){
	int a, b;
	cin >> a >> b;

	cout << 100 << " " << 100 << endl;
	char grid[100][100];
	for (int i = 0; i < 50; i++){
		for (int j = 0; j < 100; j++){
			grid[i][j] = '.';
		}
	}
	for (int i = 50; i < 100; i++){
		for (int j = 0; j < 100; j++){
			grid[i][j] = '#';
		}
	}
	for (int i = 1; i < 49; i++){
		for (int j = 0; j < 100; j++){
			if (b != 1){
				if (j % 3 == i % 3){
					grid[i][j] = '#';
					b--;
				}
			}else{
				i = MOD, j = MOD;
			}
		}
	}
	for (int i = 51; i < 100; i++){
		for (int j = 0; j < 100; j++){
			if (a != 1){
				if (j % 3 == i % 3){
					grid[i][j] = '.';
					a--;
				}
			}else{
				i = MOD, j = MOD;
			}
		}
	}
	for (int i = 0; i < 100; i++){
		for (int j = 0; j < 100; j++){
			cout << grid[i][j];
		}
		cout << endl;
	}
}

