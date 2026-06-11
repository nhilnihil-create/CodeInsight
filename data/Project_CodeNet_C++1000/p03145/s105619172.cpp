#include <bits/stdc++.h>
#define ll long long
using namespace std;
long long fpb(long long x, long long y) { 
    return (y == 0) ? x : fpb(y, x % y); 
}
long long kpk(long long x, long long y) { 
    return x * (y / fpb(x, y)); 
}
bool cmp(long long a,long long b)
{
    return a>b;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a,b,c;
    cin>>a>>b>>c;
    cout<<a*b/2<<endl;
}