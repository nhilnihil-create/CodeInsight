#include<iostream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<ctime>
#include<vector>
#include<queue>
#include<map>
#include<deque>
#include<stack>
#include<algorithm>
#define N
using namespace std;
const int INF=0x7fffffff;
const double Pi=acos(-1);
int main()
{
	int i;
	string S;
	cin>>S;
	for(i=0;i<=2;i++)
	{
		if(S[i]=='1')S[i]='9';
		else if(S[i]=='9')S[i]='1';
	}
	cout<<S;
	return 0;
}
