#include <iostream>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;
using ll = long long;

int main()
{
    ll x,y;
    cin>>x>>y;

    ll ans=1;
    while(y/x>=2){
        ans++;
        x*=2;
    }

    cout << ans << endl;

    return 0;
}