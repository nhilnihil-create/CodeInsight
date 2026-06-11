#include <stdio.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <string>
#include <cstring>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <ctime>
#include <vector>
#include <fstream>
#include <list>
#include <iomanip>
#include <numeric>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define ms(s) memset(s, 0, sizeof(s))
const int INF = 1e9;
inline int read(){
	int X = 0,w = 0 ;
	char ch = 0;
	while(!isdigit(ch)) {w |= ch == '-';ch = getchar();}
	while(isdigit(ch)) X = (X<<3) + (X<<1) + (ch ^ 48),ch = getchar();
	return w ? -X : X;
}
map<pair<string,string>,ll> m;
char s[105];
int main()
{
	int n;
	cin>>n;
	cin>>s;
	for(int i=0;i<(1<<n);i++)
	{
		string s1;
		string s2;
		for(int j=0;j<n;j++)
		{
			if(i&(1<<j))
			{
				s1+=s[j];
			}
			else
			{
				s2+=s[j];
			}
		}
		m[make_pair(s1,s2)]++;
	}
	ll sum=0;
	for(int i=0;i<(1<<n);i++)
	{
		string s1;
		string s2;
		for(int j=n-1;j>=0;j--)
		{
			if(i&(1<<j))
			{
				s2+=s[j+n];
			}
			else
			{
				s1+=s[j+n];
			}
		}
		sum+=m[make_pair(s1,s2)];
	}
	cout<<sum<<endl;
	return 0;
}