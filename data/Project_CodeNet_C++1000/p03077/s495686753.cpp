#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ll n;
    cin>>n;
    vector<ll> a(5);
    for(int i = 0;i < 5;++i) {
        cin>>a[i];
    }
    ll tm=(n+a[0]-1)/a[0];
    ll mi=a[0];
    for(int i = 1;i < 5;++i) {
        mi=min(mi,a[i]);
        if(a[i]>=a[i-1])++tm;
        else {
            tm=(n+mi-1)/mi;
            tm+=i;
        }
        //cerr<<"tm:"<<tm<<endl;
    }
    cout<<tm<<endl;
    return 0;
}
