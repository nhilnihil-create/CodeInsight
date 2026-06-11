#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll a,b,c,k;
    cin>>a>>b>>c>>k;

    cout<<(a-b)*(k%2?-1:1)<<"\n";

    return 0;
}
