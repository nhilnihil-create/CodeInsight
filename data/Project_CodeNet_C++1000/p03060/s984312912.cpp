#include<bits/stdc++.h>

#define ll long long
#define debug(x) cout<<x<<"DE"<<endl;

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n;
    cin>>n;
    ll v[n+1],c[n+1];
    for(int i=1;i<=n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>c[i];
    }
    ll x=0;
    for(int i=0;i<(1<<n);i++){
        ll g=0,d=0;
        for(int j=0;j<n;j++){
            if((i>>j)&1){
                g+=v[j+1],d+=c[j+1];
            }
        }
        x=max(x,g-d);
    }
    cout<<x;
}
