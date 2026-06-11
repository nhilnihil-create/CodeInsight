#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <iostream>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#define ll long long
#define IOS std::ios::sync_with_stdio(false);

using namespace std;
const int inf = 0x3f3f3f3f;
const ll mod =  1e9 + 7;

int main()
{
    IOS
    string a,b;
	cin>>a>>b;
	a = a + a;
	for(int i=0,j=0;i<a.size();i++)
	{
		if(a[i] == b[j])
		{
			j++;
		}
		else
		{
			j = 0;
		}
		if(j == b.size())
		{
			cout<<"Yes"<<endl;
			return 0;
		}
	}
	cout<<"No"<<endl;

    return 0;
}
