#pragma GCC optimize "-O3"
#include <bits/stdc++.h>
using namespace std;
#define lo long
const long long lmax=1999999999;
const long long lmx=1999999999999999999;
long long dm,k,d,m,ans,q,n;
string s;
int main(){std::ios::sync_with_stdio(false);
cin>>n;
cin>>s;
cin>>q;
while(q--)
{
	cin>>k;
	dm=d=m=ans=0;
	for(long long i=0;i<n;i++)
	{
		if(s[i]=='C')
		{
			ans+=dm;
		}
		else if(s[i]=='M')
		{
			dm+=d;
			m++;
		}
		else if(s[i]=='D')
		{
			d++;
		}
		if(i+1>=k)
		{
			if(s[i-k+1]=='D')
			{
				dm-=m;
				d--;
			}
			else if(s[i-k+1]=='M')
			{
				m--;
			}
		}
	}
	cout<<ans<<endl;
}
}
/*

                   *         *
                  * *       * *
                 *   *     *   *
                *     *   *     *
               *       * *       *
               *        *        *
                *               *
                 *             *
                  *           *
                   *         *
                    *       *
                     *     *
                      *   *
                       * *
                        *



*/



