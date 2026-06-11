#include <bits/stdc++.h>
using namespace std;


int main(){
	int h, w;
	cin >> h >> w;

	vector<string> row; 
	cin.ignore();
	for(int i=0;i<h;i++){
		string tmp;
		getline(cin, tmp, '\n');
		row.push_back(tmp);
	}
	int qr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
	int qc[] = {-1, 0, 1, -1, 1, -1, 0, 1};
	for (int r = 0; r < h; r++){
		for(int c = 0; c < w; c++){
			if(row[r][c]=='.'){
				int sum = 0;
				for(int q=0; q<8; q++){
					if((0 <= r+qr[q]) && (r+qr[q] < h) && (0 <= c+qc[q]) && (c+qc[q] < w)){
						if(row[r+qr[q]][c+qc[q]]=='#'){ sum ++; }
					}
				}

				row[r][c] = (char) (48+sum);
			}
		}
	}
	for(int i=0;i<h;i++){
		cout << row[i] << endl;
	}
}