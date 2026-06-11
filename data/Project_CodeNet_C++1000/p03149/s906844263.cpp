#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void)
{
	bool seven = false;
	bool one = false;
	bool nine = false;
	bool four = false;
	int nums[4];

	for (int i = 0; i < 4; i++)
	{
		cin >> nums[i];
	}

	for (int i = 0; i < 4; i++)
	{
		if (nums[i] == 1)
			one = true;
		else if (nums[i] == 7)
			seven = true;

		else if (nums[i] == 4)
			four = true;

		else if (nums[i] == 9)
			nine = true;

		
	}

	if (one && seven && four && nine)
		cout << "YES";
	else
		cout << "NO";
}