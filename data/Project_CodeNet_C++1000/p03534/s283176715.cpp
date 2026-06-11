#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
#include<queue>
#include<map>
#include<stack>
#include<fstream>
#include<stdlib.h>
#include<set>
#include<climits>
#include<cmath> 
#include<memory.h> 
#include<sstream>
#include<time.h>
using namespace std;
const long long BIGER=1000000000000000;
const int BIG=1000000000;
const int MOD=1000000007;
vector<char>vt;
int g1=0,g2=0,g3=0;
bool ypa(int k)
{
	if(g1==0&&g2==0&&g3==0)
	{
		return true;
	}
	if(k>2)
	{
		if(g1>0&&vt[k-2]!='a'&&vt[k-3]!='a')
		{
			vt.push_back('a');
			g1--;
			if(ypa(k+1))
			{
				return true;
			}
			vt.pop_back();
			g1++;
		}
		if(g2>0&&vt[k-2]!='b'&&vt[k-3]!='b')
		{
			vt.push_back('b');
			g2--;
			if(ypa(k+1))
			{
				return true;
			}
			vt.pop_back();
			g2++;
		}
		if(g3>0&&vt[k-2]!='c'&&vt[k-3]!='c')
		{
			vt.push_back('c');
			g3--;
			if(ypa(k+1))
			{
				return true;
			}
			vt.pop_back();
			g3++;
		}
	}
	else
	{
		if(g1>0&&vt[k-2]!='a')
		{
			vt.push_back('a');
			g1--;
			if(ypa(k+1))
			{
				return true;
			}
			vt.pop_back();
			g1++;
		}
		if(g2>0&&vt[k-2]!='b')
		{
			vt.push_back('b');
			g2--;
			if(ypa(k+1))
			{
				return true;
			}
			vt.pop_back();
			g2++;
		}
		if(g3>0&&vt[k-2]!='c')
		{
			vt.push_back('c');
			g3--;
			if(ypa(k+1))
			{
				return true;
			}
			vt.pop_back();
			g3++;
		}
	}
	return false;
}
int main()
{
    string st;
    cin>>st;
	for(int i=0;i<st.size();i++)
	{
		if(st[i]=='a')g1++;
		if(st[i]=='b')g2++;
		if(st[i]=='c')g3++;
	}
	if(g1>0)
	{
		vt.push_back('a');
		g1--;
		if(ypa(2))
		{
			cout<<"YES";
			return 0;
		}
		vt.pop_back();
		g1++;
	}
	if(g2>0)
	{
		vt.push_back('b');
		g2--;
		if(ypa(2))
		{
			cout<<"YES";
			return 0;
		}
		vt.pop_back();
		g2++;
	}
	if(g3>0)
	{
		vt.push_back('c');
		g3--;
		if(ypa(2))
		{
			cout<<"YES";
			return 0;
		}
		vt.pop_back();
		g3++;
	}
	cout<<"NO";
    return 0;
}