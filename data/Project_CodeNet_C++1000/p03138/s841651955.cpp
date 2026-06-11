#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll n,k;cin>>n>>k;
    ll a[n];
    for (int i=0;i<n;i++)
        cin>>a[i];
    ll x=0,ans=0;
    for (ll i=1LL<<60;i>0;i>>=1) {
        int c=0;
        for (int j=0;j<n;j++)
            if (a[j]&i)
                c++;
        if (n-c>c&&x+i<=k) {
            x+=i;
            ans+=i*(n-c);
        } else
            ans+=i*c;
    }
    cout<<ans<<endl;
    return 0;
}