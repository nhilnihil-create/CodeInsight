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
typedef long long int LL;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;

LL n;

int is_753(LL m)
{
	bool flag=true;
	map<int,int>ma;
	ma[3]=0,ma[5]=0,ma[7]=0;
	while(m>0)
	{
		int a=m%10;
		if(a!=3 && a!=5 && a!=7)
		{
			flag=false;
			break;
		}
		else ma[a]++;
		m/=10;
	}
	if(flag && ma[3]>0 && ma[5]>0 && ma[7]>0)return 1;
	else return 0;
}

LL dfs(LL m)
{
	if(m>n)return 0;
	else return is_753(m)+dfs(10*m+3)+dfs(10*m+5)+dfs(10*m+7);
}
	
int main()
{
	cin>>n;
	cout<<dfs(0)<<"\n";
	return 0;
}