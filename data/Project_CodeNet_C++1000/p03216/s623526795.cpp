#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <sstream>
#include <queue>
#include <deque>
#define ll long long
#define MP make_pair
#define PII pair<int, int>
#define F first
#define S second
using namespace std;
int n,ta,k;
string s;
ll res;
ll d,m,dm;
int main()
{
	cin >>n>>s>>ta;
	for (int tr=0;tr<ta;tr++)
	{
		cin >>k;
		res=d=m=dm=0;
		for (int i=0;i<n;i++)
	    {
			if (i>=k)
			{
				int t=i-k;
				if (s[t]=='D')
				{
					dm-=m;
					d--;
				}
				else if (s[t]=='M') m--;
			}
	    	if (s[i]=='D') d++;
	    	else if (s[i]=='M')
			{
				dm+=d;
				m++;
			}
			else if (s[i]=='C') res+=dm;
		}
		cout <<res<<"\n";
	}
	return 0;
}