#include <iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
 
int main() {
	int n;
	cin >> n;
	long long bb=0;
	map<long long,long long> mp;
	for(int i = 0;i<n;i++)
	{
		long long a;
		cin >> a;
		bb += a;
		mp[bb]++;
	}
	long long k=0;
	for(auto itr=mp.begin();itr!=mp.end();itr++)
	{
		long long d;
		d = itr->second;
		if(itr->first == 0)
		{
			k += d * (d + 1) / 2;
		}
		else
		{
			k += (d - 1) * d / 2;
		}
	}
    cout << k << endl;
	return 0;
}