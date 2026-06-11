#include <bits/stdc++.h>
using namespace std;
signed main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	printf(abs(c-a)<=d || abs(c-b)<=d && abs(b-a)<=d?"Yes":"No");
	return 0;
}