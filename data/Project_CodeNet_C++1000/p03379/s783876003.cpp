#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool revp2(const pair<ll,ll>&a,const pair<ll,ll>&b){return a.first>b.first;}
bool revp3(const pair<ll,ll>&a,const pair<ll,ll>&b){if(a.first==b.first)return a.second<b.second;
return a.first>b.first;}

int main()
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    ll n,a,b;
    cin>>n;vector<pair<ll,ll>>v;
    ll l1[n+1],l2[n+1];
    for(int i=1;i<=n;i++){cin>>l1[i];v.push_back({l1[i],i});}
    sort(v.begin(),v.end());
    map<ll,ll>m;
    for(int i=1;i<=n;i++){
        if(i<=(n/2))m[v[i-1].second]=v[(n/2)].first;
        else m[v[i-1].second]=v[(n/2)-1].first;
    }
    for(int i=1;i<=n;i++){
        cout<<m[i]<<endl;
    }
}
