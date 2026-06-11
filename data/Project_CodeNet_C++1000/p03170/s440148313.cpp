// code.begin();
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define pb push_back 
#define what_is(x) cerr<<#x<<" is "<<x<<endl;
#define print(v) for(auto i:v) cout<<i<<" ";cout<<endl;
#define my_time ios_base::sync_with_stdio(false);cin.tie(NULL);
#define ll long long 
#define endl "\n"
#define MOD 1000000007
const long long int INF=1e18;
#define mod 1000000007
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    ordered_set; 
//find_by_order(x)
//order_of_key(x)  


int power(int x,unsigned int y)
{
    int res=1;
    
    while(y>0)
    {
        // if y is odd multiply with result
        if(y&1)
        res=res*x;
        
        y=y>>1; // y=y/2;
        x=x*x;
        
    }
    return res;
}

int gcd(int a,int b)
{
    if(b==0)
    return a;
    
    return gcd(b,a%b);
}

ll  max3(ll  a, ll  b, ll c)
{
    return max(c, max(a, b));
}
int min3(int a, int  b, int  c)
{
    return min(a, min(b, c));
}

int  powermod(int  x, int  y, int p )
{
    int res = 1;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res % p;
}
int logg(int  a)
{
    int  x = 0;
    while (a > 1)
    {
        x++;
        a /= 2;
    }
    return x;
}


int modinv(int x)
{
    return powermod(x, mod - 2, mod);
}


int  main(){
	my_time;

int t;
t=1;
//cin>>t;int test=0;
while(t--)
{
int n;
cin>>n;

int k;
cin>>k;
int arr[n];  
for(int i=0;i<n;i++)
cin>>arr[i];

vector<bool> dp(k+1,false);

for(int i=0;i<=k;i++)
{
    for(int j=0;j<n;j++)
    {
        if(arr[j]<=i && !dp[i-arr[j]])
        dp[i]=true;
    }
}
  if(dp[k])
  cout<<"First"<<endl;
  else
  cout<<"Second"<<endl;
  
  
}
    return 0;
}


//code.end();



