#include <algorithm>
#include <iostream>
#include <string>
using namespace std;


int main()
{
	int N;
	cin >> N;
	int num[110], i = 0, j,temp, Ali=0, Bob=0;
	while (i < N)
	{
		cin >> num[i];
		i++;
	}
	sort(num, num+N, greater<int>());
	i = 0;
	while (i < N)
	{
		if (i % 2 ==0)
			Ali += num[i];
		else
			Bob += num[i];
		i++;
	}
	cout << Ali - Bob << endl;
	return 0;
}