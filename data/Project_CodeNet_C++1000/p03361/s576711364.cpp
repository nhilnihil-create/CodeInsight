#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> mat(h,vector<char>(w));
    for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> mat[i][j];
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			bool ok = false;
			if(mat[i][j]=='#'){
				if(i>0 && mat[i-1][j]=='#') ok=true;
				if(i<h-1 && mat[i+1][j]=='#') ok=true;
				if(j>0 && mat[i][j-1]=='#') ok=true;
				if(j<h-1 && mat[i][j+1]=='#') ok=true;
				if (ok==false) {cout << "No"; return 0;}
			}
			
		}
	}
	cout << "Yes";
			
}
