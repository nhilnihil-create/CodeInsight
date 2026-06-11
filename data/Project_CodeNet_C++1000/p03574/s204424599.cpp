// ConsoleApplication2.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//
#include <bits/stdc++.h>

using namespace std;




int main() {
	int H, W;
	cin >> H >> W;
	

	vector<vector<char>>A(H, vector<char>(W));
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {          /*受け取り*/
			cin >> A.at(i).at(j);
		}
	}

	int x[8] = {-1,-1,-1,0,0,1,1,1};
	int y[8] = {-1,0,1,1,-1,-1,0,1};

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (A.at(i).at(j) == '#') {
				continue;
			}int count = 0;
			for (int k = 0; k < 8; k++) {
				int ni = i + y[k];
				int nj = j + x[k];

				if (0 <= ni && 0 <= nj && ni < H && nj < W) {

				if (A.at(ni).at(nj) == '#') {
					
					count = count + 1;
					
				}
			  }
			}A.at(i).at(j) = char(count + '0');

				
		}
	}

	cout << endl;/*図の出力*/
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			cout << A.at(i).at(j);
		}cout << endl;
	}
}

