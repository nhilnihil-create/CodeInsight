#include<bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;
int a[1001][1001];

int main() {

	int r,c;
	cin>>r>>c;

	char ch;
	for (int i = 0; i < r; ++i)
	{
		for(int j=0;j<c;j++) {

			cin>>ch;
			a[i][j]=ch;
		}
	}

	for (int i = 0; i < r; ++i)
	{
		for(int j=0;j<c;j++) {

			// cin>>a[i][j];

			if(a[i][j]!=a[0][0])
				a[i][j]=-1;
		}
	}

	for (int i = 0; i < r; ++i)
	{
		for(int j=0;j<c;j++) {

			// cin>>a[i][j];

			if(a[i][j]!=-1)
				a[i][j]=0;
		}
	}


	a[r-1][c-1] = 1;
	for(int i=r-2;i>=0;--i) {
		if(a[i][c-1]==-1)
			break;
		a[i][c-1]=1;
	}
	for(int i=c-2;i>=0;--i) {
		if(a[r-1][i]==-1)
			break;
		a[r-1][i]=1;
	}

	for(int row=r-2;row>=0;row--) {
		for(int col=c-2;col>=0;col--) {
			if(a[row][col]==-1)
				continue;
			if(a[row+1][col]!=-1)
				a[row][col] =  a[row+1][col];
			if(a[row][col+1]!=-1)
				a[row][col] = (a[row][col] + a[row][col+1])%M;
		}
	}



	cout<<a[0][0];

	return 0;
}