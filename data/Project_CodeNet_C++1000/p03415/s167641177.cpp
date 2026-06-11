#include <iostream>
#include<cmath>
#include<math.h>
#include<algorithm>
#include<fstream>
#include<queue>
using namespace std;
void ll(){
	std::ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(0);
}
int main()
{
	ll();

	int i = 0, j = 0;
	char arr[100][100];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		
			cin>>arr[i][j];
		
	}
	while (i < 3 && j < 3)
	{
		cout<<arr[i++][j++];
	}
	cout << endl;
}