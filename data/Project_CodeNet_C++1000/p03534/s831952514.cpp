#include <iostream>
#include <fstream>
#include <iomanip>
#include <math.h>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <string>
#include <string.h>
#include <sstream>
#include <ctime>

using namespace std;

#define eps 1e-12
#define pi 3.14159265358979323846
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define bgn begin
#define ll long long
#define ld long double
#define ull unsigned long long
#define ii pair<ll,ll>









const int N=1e5+10;
int n,n2,c[8];
char s[N];





void solve()
{
	for(int i=0;i<3;i++)c[i]=0;
	cin>>s;
	n=strlen(s);
	for(int i=0;i<n;i++)
	{
		c[s[i]-'a']++;
	}
	n2=n/3;
	for(int i=0;i<3;i++)
	{
		if(c[i]<n2||c[i]>n2+1)
		{
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
}

int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);
#ifdef localProject
	freopen("in.txt","r",stdin);
#endif
	solve();
	return 0;
}