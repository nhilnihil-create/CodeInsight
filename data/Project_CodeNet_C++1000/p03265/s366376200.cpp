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
	int a,b,c,d;cin>>a>>b>>c>>d;
	int x=c-a,y=d-b;
	cout<<c-y<<" "<<d+x<<" "<<a-y<<" "<<b+x<<"\n";
}