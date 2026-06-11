#include<bits/stdc++.h>
using namespace std;

#define fastio() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

bool sortby(const pair<long long,long long> &a, const pair<long long,long long> &b)
{
    if(a.first==b.first) return a.second>b.second;
    return a.first<b.first;
}

void _case()
{
    long long n,i,m,x,y,ans=0;
    vector<pair<long long,long long> > v;
    cin>>n>>m;
    for(i=0;i<n;i++){
        cin>>x>>y;
        v.push_back({x,y});
    }
    sort(v.begin(),v.end(),sortby);
    for(i=0;i<n;i++){
        if(v[i].second>=m){
            ans+= v[i].first*m;
            m-=m;
            break;
        }
        else{
            ans+= v[i].first*v[i].second;
            m-=v[i].second;
        }
    }
    cout<<ans<<'\n';
}

main()
{
    fastio();
    _case();

}

