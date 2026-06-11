#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    map<int,int>mp;
    rep(i,n){
        mp[a[i]]=mp[a[i]-1]+1;
    }
    int ans=0;
    for(auto&p:mp){
        ans=max(ans,p.second);
    }
    cout<<n-ans<<endl;
}