#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> data(H + 2, vector<char>(W + 2));
  
  for (int i = 0; i < H + 2; i++) {
  	for (int j = 0; j < W + 2; j++) {
    	if (i == 0 || j == 0 || i == H + 1 || j == W + 1) {
        	data.at(i).at(j) = '.';
        }
        else {
        	cin >> data.at(i).at(j);
        } 
    }
  }
  
  int num = 0;
  for (int i = 1; i < H + 1; i++) {
  	for (int j = 1; j < W + 1; j++) {
    	for (int k = -1; k <= 1; k++) {
        	for (int l = -1; l <= 1; l++) {
            	if (data.at(i + k).at(j + l) == '#') {
                	num++;
                }
            }
        }
        if (data.at(i).at(j) == '#') {
        	cout << '#';
        }
        else {
        	cout << num;
        }
        num = 0;
    }
    cout << endl;
  }
}
