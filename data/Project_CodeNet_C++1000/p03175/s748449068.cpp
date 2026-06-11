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
vector<int>v[100005];
int b[100005],w[100005];

void dfs(int r,int p){
    int x=1,y=1;
    for(auto i : v[r])
        if(i!=p){
            dfs(i,r);
            x=(x*(w[i]+b[i]))%mod;
            y=(y*w[i])%mod;
        }
    b[r]=y,w[r]=x;
}

int32_t main()
{
    fast
    int x,y,n;  cin>>n;
    f(i,1,n-1){
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,1);
    cout<<(b[1]+w[1])%mod;
}