#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main()
{
    ll a,b,c;
    cin>>a>>b>>c;
    map<ll,int>m;
    m[a]++;
    m[b]++;
    m[c]++;
    if(m[a]==1)cout<<a;
    else if(m[b]==1)cout<<b;
    else  cout<<c;

    return 0;
}
