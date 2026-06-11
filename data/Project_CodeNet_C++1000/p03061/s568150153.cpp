#include<bits/stdc++.h>
using namespace std;
#define PI          acos(-1)
#define INF         100000000
#define sc(n)       scanf("%d",&n);
#define ssc(n)      scanf("%s",n);
#define lsc(n)      scanf("%lld",&n);
#define dsc(n)      scanf("%lf",&n);
#define csc(n)       scanf("%c",&n);
#define LL          long long int
#define UI          unsigned int
#define ULL         unsigned long long int
#define DB          double
#define pii         pair<int,int>
#define VI          vector<int>
#define MII         map<int,int>
#define PB          push_back
#define MP          make_pair
#define M(mx,a)     mx=max(mx,a)
#define IT          ::iterator
#define all(a)      a.begin(),a.end()
#define mems(a,b)   memset(a,b,sizeof(a))
#define F(i,a,b)    for(i=a;i<b;i++)
#define IN(n,aa)    for(i=0;i<n;i++)scanf("%d",&aa[i]);
#define PNT(n,aa)   for(i=0;i<n;i++)printf("%lld ",aa[i]);
#define mod         1000000007
#define NUM         10000009
#define NUM2        1000000000


int main()
{
    int T=1,QQ=0;
    //cin >> T ;
    while(T--)
    {
        int n,i,j,k,g;
        cin >> n ;
        int aa[n],left[n],right[n];
        for(i=0;i<n;i++)sc(aa[i]);
        g=aa[0];
        for(i=0;i<n;i++)
        {
            g=__gcd(g,aa[i]);
            left[i]=g;
        }
        g=aa[n-1];
        for(i=n-1;i>=0;i--)
        {
            g=__gcd(g,aa[i]);
            right[i]=g;
        }
        g=max(right[1],left[n-2]);
        for(i=1;i<n-1;i++)g=max(g,__gcd(left[i-1],right[i+1]));
        cout << g ;
    }
}

//printf("Case %d: ",++QQ);
