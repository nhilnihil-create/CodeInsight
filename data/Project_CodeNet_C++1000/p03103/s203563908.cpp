/*
ID: hafiz.i1
TASK: milk2
LANG: C++
*/
#include<bits/stdc++.h>

#define ll long long
#define debug(x) cout<<x<<"DE"<<endl;

using namespace std;



int main()
{
//    freopen("milk2.in", "r", stdin);
//    freopen("milk2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n,m,s=0;
    cin>>n>>m;
    ll a[n+1],b[n+1];vector<pair<ll,ll>>v;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i];
        v.push_back({a[i],b[i]});
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++){
        if(v[i-1].second>=m)s+=(m*v[i-1].first),m=0;
        else s+=(v[i-1].second*v[i-1].first),m-=v[i-1].second;
        if(m==0)break;
    }
    cout<<s<<endl;
}
