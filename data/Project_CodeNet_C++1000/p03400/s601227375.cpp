#include<bits/stdc++.h>
 
#define lli long long int
#define endl "\n"
 
using namespace std;
 
typedef long long int LLI;
typedef double DB;
 
void fastio()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
}
 
 
bool comparator(pair<lli,lli> a,pair<lli,lli> b)
{
    if(a.first>b.first)
        return true;
    else if (a.first==b.second)
    {
        if(a.second>=b.second)
            return false;
        return true;
    }
    return false;
}
 
int mods(int x)
{
    if(x>0)
        return x;
    return -x;
}
 
lli gcd(lli a,lli b)
{
    return __gcd(a,b);
}
 
lli lcm(lli x,lli y,lli z)
{
    lli j=gcd(x,y);
    lli k=gcd(y*x/j,z);
    return (((x*y)/j)*z)/k;
} 

int isprime(int n)
{
    for(int i=2;i<=sqrt(n);++i)
    {
        if(n%i==0) return 0;
    }
    return 1;
}

int main()
{
    fastio();
    int n,d,x; cin>>n>>d>>x; int arr[n]={0}; for(int i=0;i<n;++i) cin>>arr[i]; x+=n; --d;
    for(int i=0;i<n;++i)
    {
        x+=(d/arr[i]);    
    }
    cout<<x;
    return 0;
}