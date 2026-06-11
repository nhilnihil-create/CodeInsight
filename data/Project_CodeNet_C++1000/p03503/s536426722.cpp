#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()	{
	int n;
	cin >> n;
	vector< vector<int> > freq_max(n);
	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < 10; j++)	{
			int tmp;
			cin >> tmp;
			freq_max[i].push_back(tmp);
		}	
	}
	
	vector< vector<int> > profits(n);

	for (int i = 0; i < n; i++)	{
		for (int j = 0; j < 11; j++)	{
			int tmp;
			cin >> tmp;
			profits[i].push_back(tmp);	
		}
	}

	long long acc = -1e9; 
	for (int i = 1; i < 1024; i++)	{
		int temp = 0;
		for (int j = 0; j < n; j++)	{
			int temp1 = 0;
			for (int k = 0; k < 10; k++)	{
				if ((i>>k&1) && (freq_max[j][k] == 1)) temp1++; 
			}
			temp += profits[j][temp1];
		}
		if (acc < temp) acc = temp;
	}	
	cout << acc << endl;
	return 0;
}
