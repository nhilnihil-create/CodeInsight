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
int main()
{
	LL n;
	LL ans=MOD;
	cin>>n;
	while(n>=100)
	{
		ans=min(ans,(LL)abs((n%1000)-753));
		n/=10;
	}
	cout<<ans<<"\n";
	return 0;
}