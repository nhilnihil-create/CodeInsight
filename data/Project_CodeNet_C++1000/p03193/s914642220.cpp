// ConsoleApplication1.cpp : Defines the entry point for the console application.
//
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <cmath>

using namespace std;

const long long bigNum = 1000000007;

int gcd(int a, int b)
{
	int buffer = a;
	if (b > a)
	{
		a = b;
		b = buffer;
	}

	int remainder = a%b;
	while (remainder != 0)
	{
		a = b;
		b = remainder;
		remainder = a%b;
	}
	return b;
}

long long comb(int n, int k)
{
	vector<int> setofNums;
	long long ret = 1;
	for (int i = 1; i <= k; i++)
	{
		setofNums.push_back(i);
	}
	for (int i = 0; i < k; i++)
	{
		ret = ret * (n - i);
		for (auto it : setofNums)
		{
			if (ret % it == 0)
			{
				ret /= it;
				it = bigNum;
			}
		}
		if (ret > bigNum)
			ret %= bigNum;
	}
	return ret;
}

int main()
{
	int N,H,W;
	
	cin >> N >> H >> W;
	int output = 0;
	for(int i = 0; i < N; i++)
	{
		int A, B;
		cin >> A >> B;
		if(A >= H && B >=W)
			output++;
	}

	cout << output << endl;
	return 0;
}