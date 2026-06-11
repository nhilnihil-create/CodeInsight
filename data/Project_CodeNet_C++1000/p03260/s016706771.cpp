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
using namespace std;
//typedef __int64 LL;
//typedef long long int LL;
typedef pair<int,int> P;
//typedef pair<LL,LL> PL;

const int MOD=1000000007;

	
int main()
{
	string s="No";
	int a,b;cin>>a>>b;
	if((a*b)%2==1)s="Yes";
	cout<<s<<"\n";
}