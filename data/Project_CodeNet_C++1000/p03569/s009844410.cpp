#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<climits>
#include<iostream>
#include<sstream>
#include<utility>
#include<map>
#include<vector>
#include<queue>
#include<algorithm>
#include<set>
#include<stack>
#include<functional>
#include<ios>
#include<iomanip>

using namespace std;
typedef long long ll;
typedef pair<int,int>P;

int main()
{
	string s;
	vector<int>sp;
	cin>>s;
	string nxs="";
	for(int i=0;i<s.length();i++)
	{
		if(s[i]!='x')
		{
			nxs+=s[i];
			sp.push_back(i);
		}
	}

	for(int i=0;i<nxs.length();i++)
	{
		if(nxs[i]!=nxs[nxs.length()-1-i])
		{
			cout<<"-1"<<endl;
			return 0;
		}
	}
	int lp=0,rp=nxs.length()-1,lx=0,rx=s.length()-1;
	int cnt=0;
	for(;lp<=rp;)
	{
		int lc=sp[lp]-lx;
		int rc=rx-sp[rp];
		if(lc!=rc)
		{
			cnt+=abs(lc-rc);
		}
		lx=sp[lp];
		rx=sp[rp];
		lp++;
		rp--;
	}
	

	cout<<cnt<<endl;
}