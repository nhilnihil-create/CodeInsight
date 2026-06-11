#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll n;cin>>n;
    ll val = n + (n%2?0:1);
    vector< pair<ll,ll> >ans;
    for(ll i=1;i<=n;i++)for(ll j=i+1;j<=n;j++)if(i+j!=val)ans.push_back({i,j});
    cout<<ans.size()<<"\n";
    for(auto &ele:ans)cout<<ele.first<<" "<<ele.second<<"\n";
}