#include<bits/stdc++.h>
#include<tuple>

#define ll long long
#define mod 1000000007

using namespace std;



int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    tuple<ll,ll,ll>g;
    vector<tuple<ll,ll,ll>>v;
    cin>>n;ll x[n+1],y[n+1],h[n+1];
    for(int i=1;i<=n;i++){
        cin>>x[i]>>y[i]>>h[i];
        if(h[i]>=1)g=make_tuple(x[i],y[i],h[i]);
    }
    for(int i=0;i<=100;i++){
        for(int j=0;j<=100;j++){bool ok=true;
            ll H=get<2>(g)+abs(get<0>(g)-i)+abs(get<1>(g)-j);H=max(H,0ll);
            for(int k=1;k<=n;k++){
                ll hi=H-abs(x[k]-i)-abs(y[k]-j);hi=max(hi,0ll);
                if(h[k]!=hi)ok=false;
            }
            if(ok)v.push_back(make_tuple(i,j,H));
        }
    }
    cout<<get<0>(v[0])<<" "<<get<1>(v[0])<<" "<<get<2>(v[0])<<endl;
}
