#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int i,j;
	char s[3][3];
	for(i=0;i<3;i++)
	for(j=0;j<3;j++)
	{
		cin >> s[i][j];
	}
	for(int i=0;i<3;i++)
	{
		cout << s[i][i];
	}
	cout << endl;
	return 0;
}
