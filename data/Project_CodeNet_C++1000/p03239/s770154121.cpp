#include<bits/stdc++.h>

#define ll long long
#define mod 1000000007

using namespace std;



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,t;
    cin>>n>>t;
    ll c[n+1],tt[n+1];
    vector<pair<ll,ll>>v;
    for(int i=1;i<=n;i++){
        cin>>c[i]>>tt[i];
        v.push_back({c[i],tt[i]});
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++){
        if(v[i-1].second<=t){
            cout<<v[i-1].first<<endl;return 0;
        }
    }
    cout<<"TLE\n";
}
