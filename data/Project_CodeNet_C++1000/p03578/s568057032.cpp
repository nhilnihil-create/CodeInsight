#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
//typedef __int64 LL;
//typedef long long int LL;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;
int d[200010],t[200010];
map<int,int>mpd,mpt;
int main()
{
	string ans="YES";
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>d[i];
		mpd[d[i]]++;
	}
	cin>>m;
	for(int i=0;i<m;i++)
	{
		cin>>t[i];
		mpt[t[i]]++;
	}
	
	for(int i=0;i<m;i++)
	{
		int x=t[i];
		if(mpd[x]<mpt[x]){ans="NO";break;}
	}
	cout<<ans<<"\n";
	return 0;
}