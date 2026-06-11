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

int b[100005][2],n,a[105];
int solve(int rem,int prev){
    int &x=b[rem][prev];
    if(x!=-1)   return x;
    x=1;
    f(i,1,n)
        if(rem-a[i]>=0)
            x&=solve(rem-a[i],prev^1);
    x=x^1;
    return x;
}

int32_t main()
{
    fast
    int k;    cin>>n>>k;
    f(i,0,k+1)  b[i][0]=b[i][1]=-1;
    f(i,1,n)    cin>>a[i];
    if(solve(k,0)==0)   cout<<"Second";
    else      cout<<"First";
}