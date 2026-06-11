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
#include <queue>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; ++i)
#define ALL(v) v.begin(), v.end()
typedef long long ll;

int main()
{
	int n,kk;
	cin >> n >> kk;
	vector<int> x(n),y(n);
	rep(i,n)cin >> x[i] >> y[i];
	vector<int> sortx(n),sorty(n);

	rep(i,n)
	{
		sortx[i]=x[i];
		sorty[i]=y[i];
	}
	sort(ALL(sortx));
	sort(ALL(sorty));

	ll ans =1LL *  (sortx[n-1]-sortx[0])*(sorty[n-1]-sorty[0]);

	for(int i= 0;i<n;i++)
		for(int j= i+1;j<n;j++)
			for(int k = 0;k< n;k++)
				for(int l=k+1;l<n;l++)
				{
					int c = 0;
					rep(m,n)
					{
						if(sortx[i]<=x[m]&&x[m]<=sortx[j]&&sorty[k]<=y[m]&&y[m]<=sorty[l])
						c++;
					}

					if(c>=kk)
					{
						//cout<<c<<endl;
						ans = min (ans , 1LL*(sortx[j]-sortx[i])*(sorty[l]-sorty[k]) );
					}
				}


	cout<<ans<<endl;
	return 0;
}