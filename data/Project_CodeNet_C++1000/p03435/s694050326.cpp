#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[3];
int b[3];
int c[3][3];

int main() {
	for(int i=0;i<3;i++) {
		for(int j=0;j<3;j++) {
			cin>>c[i][j];
		}
	}
	a[0]=0;
	a[1]=c[1][0]-c[0][0];
	a[2]=c[2][0]-c[0][0];
	b[0]=c[0][0];
	b[1]=c[0][1];
	b[2]=c[0][2];
    string ans="Yes";
	for(int i=0;i<3;i++) {
		for (int j=0;j<3;j++) {
			if(a[i]+b[j]!=c[i][j]) ans="No";
		}
	}
	cout << ans << endl;
}