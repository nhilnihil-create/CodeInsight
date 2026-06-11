#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    int x,y,z,k;cin>>x>>y>>z>>k;
    ll a[x],b[y],c[z];
    for (int i=0;i<x;i++)
        cin>>a[i];
    for (int i=0;i<y;i++)
        cin>>b[i];
    for (int i=0;i<z;i++)
        cin>>c[i];
    vector<ll> d,e;
    for (int i=0;i<x;i++)
        for (int j=0;j<y;j++)
            d.push_back(a[i]+b[j]);
    sort(d.begin(),d.end(),greater<ll>());
    for (int i=0;i<k&&i<d.size();i++)
        for (int j=0;j<z;j++)
            e.push_back(d[i]+c[j]);
    sort(e.begin(),e.end(),greater<ll>());
    for (int i=0;i<k;i++)
        cout<<e[i]<<endl;
    return 0;
}