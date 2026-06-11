#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<queue>
#include<set>
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn=1e9;


int main()
{
	char s[1000];
	int w;
	while(cin>>s>>w)
	{
		for(int i=0;s[i]!='\0';i++)
		{
			if(i%w==0)cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}
