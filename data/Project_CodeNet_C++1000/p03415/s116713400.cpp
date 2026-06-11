#include <bits/stdc++.h>
using namespace std;
typedef long long int LLI;

int main()
{
	char arr[3][3];
	for(int i = 0; i < 3; i++)
		for(int j = 0; j < 3; j++)
			cin >> arr[i][j];
	cout << arr[0][0] << arr[1][1] << arr[2][2];
}