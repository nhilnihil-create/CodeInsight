 
/* Great things never come from comfort zones,
"whatever the mind of a man can conceive and believe,it can achieve." */
 
#include <bits/stdc++.h>
#define ll long long
#define scf(n) scanf("%d",&n)
#define lscf(n) scanf("%lld",&n)
#define lpri(n) printf("%lld ",n)
#define pri(n) printf("%d ",(int)n)
#define prin(n) printf("%d\n",(int)n)
#define lprin(n) printf("%lld\n",n)
#define rep(i,ini,n) for(int i=ini;i<(int)n;i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x)     x.begin(),x.end()
#define tc   int tt; scf(tt); while(tt--)
#define inf INT_MAX
#define ninf INT_MIN
#define gcd __gcd
#define bitcount(n) __builtin_popcount(n)
typedef double dd;
using namespace std;
const ll mod =1e9+7;
const int N = 2e5+7;

int main()
{
    
    int n;
    scf(n);
    
    int a[n];
    
    rep(i,0,n)
    {
        scf(a[i]);
            
        a[i]=a[i]-(i+1);
    
    }    
    
    sort(a,a+n);
    
    int b=0;
    
    ll res=0;
    
    if(n&1)
    b=a[n/2];
    
    
    else
    b=(a[n/2]+a[n/2-1])/2;
    
    rep(i,0,n)
    res+=abs(a[i]-b);
    
    lprin(res);
    
}