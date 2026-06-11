#include <iostream>
#include <string>
#include <unordered_map>
#include <stdio.h>
#include <list>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

int main()
{
	int n;cin >> n;
	vector<int> a(n);
	rep(i,n)cin >> a[i];

	int ma=INT_MIN;
	int ma_n;
	int mi=INT_MAX;
	int mi_n;

	rep(i,n)
	{
		if(ma<a[i])
		{
			ma=a[i];
			ma_n=i;
		}
		if(mi>a[i])
		{
			mi=a[i];
			mi_n=i;
		}
	}

	cout<<2*n-1<<endl;

	if(ma+mi<=0)
	{	
		rep(i,n)
		{
			cout<<mi_n+1<<' '<<i+1<<endl;
		}
		for(int i=n-1;i>0;i--)
		cout<<i+1<<' '<<i<<endl;
	}
	else
	{
		rep(i,n)
		{
			cout<<ma_n+1<<' '<<(i+1)<<endl;
		}
		for(int i=0;i<n-1;i++)
		{
			cout<<i+1<<' '<<i+2<<endl;
		}
	}

	return 0;
}