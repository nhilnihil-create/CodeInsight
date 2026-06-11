#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int c[3][3], a[3], b[3];
bool check = true;

int main(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cin >> c[i][j];
		}
	}

	a[0] = 0;
	b[0] = c[0][0];
	b[1] = c[0][1];
	b[2] = c[0][2];
	a[1] = c[1][0]-b[0];
	a[2] = c[2][0]-b[0];
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(a[i]+b[j]!=c[i][j]){
				check = false;
				break;
			}
		}
	}
	if(check){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
}
