#include<iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	string str;
	long long Num;
	cin >> str;
	cin >> Num;

	long long intStrNum = str.size();

	for (long long i = 0;i < min(intStrNum, Num);i++)
	{
		if (str[i] != '1')
		{
			cout << str[i] << endl;
			return 0;
		}
	}

	cout << "1" << endl;
	return 0;


}
