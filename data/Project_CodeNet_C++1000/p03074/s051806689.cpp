#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    ll n,k;cin>>n>>k;
    string s;cin>>s;
    ll prv=-1,cnt=0;
    vector< pair<ll,ll> > vec;
    for(ll i=0;i<n;i++){
        ll val = s[i]-'0';
        if(val==prv)cnt++;
        else{
            if(prv!=-1)vec.push_back({prv,cnt});
            cnt=1;
            prv=val;
        }
    }
    vec.push_back({prv,cnt});
    vector<ll> prfx(vec.size()+1);
    for(ll i=0;i<(ll)vec.size();i++)prfx[i+1]=prfx[i] + vec[i].second;
    ll ans = 0;
    for(ll i=0;i<(ll)vec.size();i++){
        ll r = i + (vec[i].first==0?2*k:2*k+1);
        ll cnt = prfx[min(r,(ll)vec.size())]-prfx[i];
        ans=max(ans,cnt);
    }
    cout<<ans;
}
