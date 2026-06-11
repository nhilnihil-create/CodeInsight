#include <iostream>
#include <cstdlib>
#include <bitset>
#include <map>
#include <iomanip>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>
#include <sstream>
#include <math.h>

using namespace std;

#define ll long long
#define vecll vector<long long>
#define vec2ll vector<vector<long long>>
#define vecchar vector<char>
#define vecstr vector<string>
#define vec2str vector<vector<string>>
#define vecbool vector<bool>
#define vec2bool vector<vector<bool>>
#define pairll pair<ll,ll>
#define vecpairll vector<pair<long long,long long>>
#define forll(s,a,b) for(long long s = a;s < b;s++)
#define forllde(s,a) for(long long s = a;s >= 0;s--)

#define Pi 3.1415926535897932384626

int main() {
	ll n,ans=0;
	string s="No";
	bool flag = false;

	cin >> s;

	string operate;

	vecbool isAdd(3, false);

	forll(i, 0, 2)
	{
		ll buf;
		isAdd[0] = (i % 2 == 0 ? true : false);
		forll(j, 0, 2)
		{
			isAdd[1] = (j % 2 == 0 ? true : false);
			forll(k, 0, 2)
			{
				isAdd[2] = (k % 2 == 0 ? true : false);

				buf = s[0] - '0';

				forll(l, 0, 3)
				{
					if (isAdd[l])
					{
						buf += (s[l + 1]- '0');
					}
					else
					{
						buf -= (s[l + 1]- '0');
					}

					if (buf == 7)
						break;
				}
				if (buf == 7)
					break;
			}
			if (buf == 7)
				break;
		}
		if (buf == 7)
			break;
	}

	forll(i, 0, 3)
	{
		if (isAdd[i])
			operate.push_back('+');
		else
			operate.push_back('-');
	}

	cout << s[0] << operate[0] << s[1] << operate[1] << s[2] << operate[2] << s[3] << "=7";

}