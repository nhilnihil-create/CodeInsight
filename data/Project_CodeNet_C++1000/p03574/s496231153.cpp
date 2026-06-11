#include <iostream>

using namespace std;

char a[52][52];

int main() {
	int n,m,i,j,t;
	cin >> n >> m;
	for(i=1;i<=n;i++) for(j=1;j<=m;j++) cin >> a[i][j];
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			t=0;
			if(a[i][j]=='.')
			{
				if(a[i-1][j]=='#') t++;
				if(a[i-1][j-1]=='#') t++;
				if(a[i-1][j+1]=='#') t++;
				if(a[i][j+1]=='#') t++;
				if(a[i][j-1]=='#') t++;
				if(a[i+1][j-1]=='#') t++;
				if(a[i+1][j]=='#') t++;
				if(a[i+1][j+1]=='#') t++;
				a[i][j]=t+'0';
			}
		}
	}

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++) cout << a[i][j];
		cout << "\n";
	}

	return 0;
}
