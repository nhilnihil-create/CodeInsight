//#include<bits/stdc++.h>
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
#define NUM         5009
#define NUM2        1000000000


int a[NUM],aa[NUM];
LL neww[NUM][NUM],nxt[NUM][NUM];


int main()
{
    int T=1,QQ=0;
    //cin >> T ;
    while(T--)
    {
        int n,i,j ;
        LL aaa,bbb,k ;
        cin >> n >> aaa >> bbb ;
        for(i=1; i<=n; i++)
        {
            sc(a[i]);
            aa[a[i]]=i;
        }
        for(i=0; i<=n; i++)
        {
            for(int j=0; j<=n; j++)
            {
                neww[i][j]=nxt[i][j]=INF;
            }
        }
        for(i=0; i<=n; i++)
            nxt[0][i]=neww[0][i]=0ll;
        for(i=1; i<=n; i++)
        {
            for(j=0; j<=n; j++)
            {
                if(j==aa[i])
                {
                    neww[i][j]=min(neww[i][j],nxt[i-1][j-1]);
                }
                if(j<aa[i])
                    k=nxt[i-1][j]+bbb;
                else
                    k=nxt[i-1][j]+aaa;
                neww[i][j]=min(neww[i][j],k);
            }
            nxt[i][0]=neww[i][0];
            for(j=1; j<=n; j++)
                nxt[i][j]=min(nxt[i][j-1],neww[i][j]);
        }
        cout << nxt[n][n] ;
    }
}
