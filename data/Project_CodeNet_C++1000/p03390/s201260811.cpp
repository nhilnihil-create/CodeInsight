#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
#include <queue>
 
#define LL long long
 
using namespace std;
 
int a, b;
 
int main()
{
	//freopen("test_in.txt", "r", stdin);
	//freopen("test_out.txt", "w", stdout);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		LL p = 1ll*a*b-1, x;
		for(x = sqrt(p)-2; x <= sqrt(p)+2; x++)
			if(x*x<=p && (x+1)*(x+1) > p)	break;
		LL ans = x*2-(a<=x)-(b<=x)-(1ll*x*x<=p && 1ll*x*(x+1)>p);
		cout<<ans<<endl;
	}
}