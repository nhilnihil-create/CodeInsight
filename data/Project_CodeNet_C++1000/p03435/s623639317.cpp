#include <bits/stdc++.h>
using namespace std;

int main(){
	int c[3][3];
	cin >> c[0][0] >> c[0][1] >> c[0][2];
	cin >> c[1][0] >> c[1][1] >> c[1][2];
	cin >> c[2][0] >> c[2][1] >> c[2][2];
	int maxi=0;
	for(int i=0;i<3;i++) for(int j=0;j<3;j++) maxi =max(maxi,c[i][j]);
	int a[3];
	int b[3];
	int row1 = c[0][0] + c[0][1] + c[0][2];
	int row2 = c[1][0] + c[1][1] + c[1][2];
	int row3 = c[2][0] + c[2][1] + c[2][2];
	
	int col1 = c[0][0] + c[1][0] + c[2][0];
	int col2 = c[0][1] + c[1][1] + c[2][1];
	int col3 = c[0][2] + c[1][2] + c[2][2];
	
	for(a[0] = 0;a[0]<=maxi;a[0]++){
		for(b[0]=0;b[0]<=maxi;b[0]++){
			a[1] = a[0]-(row1-row2)/3;
			a[2] = a[0]-(row1-row3)/3;
			b[1] = b[0]-(col1-col2)/3;
			b[2] = b[0]-(col1-col3)/3;
			if(a[1]<0 || a[2]<0 || b[1]<0 || b[2]<0) continue;
			//cout << endl;
			//cout << a[0] << " " << a[1] << " " << a[2] << endl;
			//cout << b[0] << " " << b[1] << " " << b[2] << endl;
			for(int k=0;k<3;k++){
				for(int r=0;r<3;r++){
					if(c[k][r] != a[k]+b[r]) goto stop; 
					}
				}
			cout<<"Yes";
			return 0;
			stop: continue;
		}
	}
	cout << "No";
	
	
	
}
