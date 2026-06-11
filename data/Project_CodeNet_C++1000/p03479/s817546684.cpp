#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1e9+7;
const int N=2e5+9;
int main()
{
    FASTINOUT;
    ll x,y,c=0;
    cin>>x>>y;
    while (x<=y)
        x*=2LL,c++;
    cout<<c;
    return 0;
}
