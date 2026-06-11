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
    int n; cin>>n; set <int> s; s.insert(n);
    int prev=s.size();
    for(;;)
    {
        if(n%2) n=3*n+1;
        else n>>=1;
        s.insert(n);
        if(prev==s.size()) {cout<<s.size()+1; return 0;}
        prev=s.size();
    }
    return 0;
}