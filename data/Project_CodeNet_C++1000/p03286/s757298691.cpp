#include <iostream>
using namespace std;
string pos( long long int k )
{
	long long int sum = 0, val = 1;
	string res = "";
	while( sum + val < k )
	{
		sum += val;
		val *= 4;
		res = "01" + res;
	}
	res = "1" + res;
	sum += val - k;
	for(int i = 0; i < res.size(); i++)
	{
		if( val <= sum )
		{
			if( res[i] == '1' )
				res[i] = '0';
			else res[i] = '1';
			sum -= val;
		}
		val /= 2;
	}
	
	return res;
}

string neg( long long int k )
{
	k = -k;
	long long int sum = 0, val = 2;
	string res = "";
	while( sum < k )
	{
		sum += val;
		val *= 4;
		res = "10" + res;
	}
	val /= 4;
	sum -= k;
	for(int i = 0; i < res.size(); i++)
	{
		if( val <= sum )
		{
			if( res[i] == '1' )
				res[i] = '0';
			else res[i] = '1';
			sum -= val;
		}
		val /= 2;
	}
	
	return res;
}

int main()
{
	long long int k;
	cin >> k;
	if( k == 0 )
		cout << 0;
	else if( k > 0 )
		cout << pos(k);
	else cout << neg(k);
	
}