#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
#define Q int tt,qq; cin>>tt ;for(qq=1;qq<=tt;qq++)
#define FAST ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main()
{
    int n;
    cin>>n;
    int a,ans=0;
    for(int i=0;i<n;i++){
        cin>>a;
        ans=__gcd(ans,a);
    }
    cout<<ans;
}
