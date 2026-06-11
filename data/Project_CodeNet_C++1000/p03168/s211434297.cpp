#include <bits/stdc++.h>      
using namespace std;            

#define    int               long long int
 #define    bp(x)         __builtin_popcount(x)
#define  ld         long double
 #define  f(i,j,n)            for(int i = j; i <= n; i++)
#define  r(i,n,j)       for(int i = n; i >= j; i--)
 #define  all(container)       container.begin() , container.end()
#define  sz(container)   (int)container.size()
 #define  ff             first
#define  ss             second
 #define  pii      pair <int , int>
#define  sp(x)       setprecision(x)
#define  mod  1000000007
#define  endl  "\n"
 #define  pb    push_back
#define  mp    make_pair
 #define  T     int ttt; cin >> ttt; while(ttt--)
#define fast ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

int power(int x, int y, int p)  
{  
    int res = 1;    
    x = x % p; 
    if (x == 0) return 0; 
    while (y > 0)  
    {     
        if (y & 1)  
            res = (res*x) % p;  
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return res; 
}
ld s[3003][3003],a[3003];

int32_t main()
{
    fast
    int n;  cin>>n;
    f(i,1,n)    cin>>a[i];
    s[1][1]=a[1];
    s[1][0]=1.00-a[1];
    f(i,2,n){
        s[i][0]=s[i-1][0]*(1.00 -a[i]);
        f(j,1,i)
            s[i][j]=s[i-1][j-1]*a[i] + s[i-1][j]*(1.00 -a[i]);
    }
    ld ans=0.00;
    f(i,n/2+1 ,n) ans+=s[n][i];
    cout<<fixed<<sp(10)<<ans;
}