#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll n,a[200005];
bool chk(ll m){
    if(m==1){
        for(ll i=1;i<n;i++)if(a[i]<=a[i-1])return 0;
        return 1;
    }
    map<ll,ll> cur;
    for(ll i=1;i<n;i++){
        if(a[i]>a[i-1])continue;
        map<ll,ll>::iterator itr;
        while( (itr=cur.upper_bound(a[i]))!=cur.end() )cur.erase(itr);
        cur[a[i]]++;
        ll val = a[i];
        while(cur[val]>=m){
            cur.erase(val);
            val--;
            cur[val]++;
            if(val==0)return 0;
        }
    }
    return 1;
}
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(ll i=0;i<n;i++)cin>>a[i];
    ll s=1,e=n;
    while(s<e){
        ll mid=(s+e)>>1;
        if(chk(mid))e=mid;
        else s=mid+1;
    }
    cout<<e;
}


