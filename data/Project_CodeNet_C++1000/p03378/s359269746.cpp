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

int main()
{
    fastio();
    int n,m,x; cin>>n>>m>>x; int arr[n]={0}; --x;
    for(int i=0;i<m;++i) {int k; cin>>k; arr[k-1]=1;}
    int sum1=0,sum2=0;
    for(int i=0;i<x;++i) sum1+=arr[i];
    for(int i=x+1;i<n;++i) sum2+=arr[i];
    cout<<min(sum1,sum2);
    return 0;
}