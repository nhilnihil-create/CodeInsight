#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<utility>
#include<functional>
#include<algorithm>
#include<bitset>
#include<ctime>
#include<cmath>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	string s;
	int res=1e9;
	cin>>s;
	for(int i=1;i<s.length();i++)
		if(s[i]!=s[i-1])
			res=min(max(i,max((int)s.length()-i,i)),res);
	cout<<min(res,(int)s.length());
	return 0;
}