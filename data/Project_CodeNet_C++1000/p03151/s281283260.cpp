#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans,sum;
vector<ll> extra;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    ll a[n],b[n];for(ll i=0;i<n;i++)cin>>a[i];
    for(ll i=0;i<n;i++){
        cin>>b[i];
        if(a[i]>=b[i])extra.push_back(a[i]-b[i]);
        else{
            sum+=(b[i]-a[i]);
            ans++;
        }
    }
    sort(extra.rbegin(),extra.rend());
    for(ll i=0;i<(ll)extra.size();i++)if(sum>0)sum-=extra[i],ans++;
    if(sum>0)return cout<<"-1" , 0;
    cout<<ans;
}

