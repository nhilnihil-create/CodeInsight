#include<bits/stdc++.h>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<cstring>
//#include<cstdlib>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<iterator>
#include<deque>

using namespace std;
#define PI          acos(-1)
#define INF         10000000000000000ll
#define sc(n)       scanf("%d",&n);
#define lsc(n)      scanf("%lld",&n);
#define dsc(n)      scanf("%lf",&n);
#define LL          long long int
#define UI          unsigned int
#define ULL         unsigned long long int
#define DB          double
#define pii         pair<int,int>
#define PB          push_back
#define MP          make_pair
#define M(mx,a)     mx=max(mx,a)
#define IT          ::iterator
#define all(a)      a.begin(),a.end()
#define mems(a,b)   memset(a,b,sizeof(a))
#define ARC(n)      for(i=0;i<n;i++)
#define ASC(n,aa)   for(i=0;i<n;i++)scanf("%lld",&aa[i]);
#define PNT(n,aa)   for(i=0;i<n;i++)printf("%lld ",aa[i]);
#define mod         1000000007
#define NUM         200010
#define NUM2        1000000000



int main()
{
    int T=1,QQ=0;
    //cin >> T ;
    while(T--)
    {
        int n,k,i,j,l,r=0,sm=0,ans=0,zero=0;
        cin >> n >> k;
        string ss;
        cin >> ss;
        vector<int> vv,vvv;
        for(i=0,j=0;i<ss.size();i=j)
        {
            while(j<ss.size()&&ss[i]==ss[j])j++;
            vv.PB(ss[i]-'0');
            vvv.PB(j-i);
        }
        for(l=0;l<vvv.size();l++)
        {
            if(l>r)r=l;
            while(zero<=k&&r<vvv.size())
            {
                if(vv[r]==0&&zero==k)break;
                if(vv[r] == 0)zero++;
                sm+=vvv[r];
                r++;
            }
            ans=max(sm,ans);
            sm-=vvv[l];
            if(vv[l]==0)zero--;
        }
        cout << ans ;
    }
}
