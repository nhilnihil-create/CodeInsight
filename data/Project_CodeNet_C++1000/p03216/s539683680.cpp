#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <cassert>
#include <iomanip>
#include <vector>
#include <cstdio>
#include <float.h>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <stack>
#include <functional>
 
using namespace std;
 
#define endl '\n'
#define MOD 1000000007
#define INF 1ll<<30
#define MAX 100010
#define eps 1e-11
#define bit_max 1ll<<32
#define _USE_MATH_DEFINES



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  // 	freopen("input.txt","r",stdin);
  // 	freopen("output.txt","w",stdout);
	int n;
	cin>>n;
	string a ;
	cin>>a;
	int q;
	long long int mc[n+5];
	mc[0] = 0;
	for(int i=0;i<n;i++)
	{
		mc[i+1] = mc[i] + (a[i]=='M');
	}
	cin>>q;
	for(int i=0;i<q;i++)
	{
		long long int k;
		cin>>k;
		long long int d=0;
		long long int dm = 0;
		long long int ans = 0;
		for(int j=0;j<n;j++)
		{
			if(j-k>=0)
			{
				if(a[j-k] == 'D')
				{
					d--;
					dm = dm - (mc[j] - mc[j-k+1]);
				}

			}
			if(a[j]=='D')
			{
				d++;
			}
			if(a[j]=='M')
			{
				dm = dm + (d);
			}
			if(a[j]=='C')
			{
				ans = ans+dm;
			}
		}
		cout<<ans<<endl;
	}
	return 0 ;
}
