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
	int n;
	cin >> n;
	int rmvsm=(n+1)-n%2;
	cout<<n*(n-1)/2-n/2<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if((i+j)!=rmvsm)
			{
				cout<<i<<' '<<j<<endl;
			}
		}
	}
	return 0;
}