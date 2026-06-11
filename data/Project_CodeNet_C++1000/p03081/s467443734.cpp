#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<char,char> p2;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,q,res=0;
    string s;
    cin>>n>>q>>s;
    vector<p2> v(q);
    for(ll i=0;i<q;i++)
    cin>>v[i].first>>v[i].second;
    ll l=0,r=n-1;
    while(l<=r){
        ll m=(l+r)/2;
        ll pos=m;
        for(ll i=0;i<q;i++)
        if(pos>=0&&pos<n&&s[pos]==v[i].first)
        pos+=(v[i].second=='R'?1:-1);
        if(pos==(-1))
        l=m+1;
        else
        r=m-1;
    }
    res-=r+1;
    l=0;
    r=n-1;
    while(l<=r){
        ll m=(l+r)/2;
        ll pos=m;
        for(ll i=0;i<q;i++)
        if(pos>=0&&pos<n&&s[pos]==v[i].first)
        pos+=(v[i].second=='R'?1:-1);
        if(pos==n)
        r=m-1;
        else
        l=m+1;
    }
    res+=l;
    cout<<res;
}
