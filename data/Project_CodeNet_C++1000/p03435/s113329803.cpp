#include<bits/stdc++.h>
#define MOD (long long)(1e9+7)
using namespace std;
int c[5][5];
int main()
{
	for(int i=0; i<3; i++) for(int j=0; j<3; j++) cin >> c[i][j];
	int ok=1;
	for(int i=1; i<3; i++)
	{
		if(c[i][1]-c[i][0] == c[i-1][1]-c[i-1][0] && c[i][2]-c[i][0] == c[i-1][2]-c[i-1][0]
		&& c[i][2]-c[i][1] == c[i-1][2]-c[i-1][1]);
		else ok=0;
		if(c[1][i]-c[0][i] == c[1][i-1]-c[0][i-1] && c[2][i]-c[0][i] == c[2][i-1]-c[0][i-1]
		&& c[2][i]-c[1][i] == c[2][i-1]-c[1][i-1]);
		else ok=0;
	}
	cout << (ok?"Yes":"No");
	return 0;
}
