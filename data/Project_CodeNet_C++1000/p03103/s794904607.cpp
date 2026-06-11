#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
int main(){
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> dat(n);
    rep(i,n){
        int a,b;
        cin>>a>>b;
        dat[i]=make_pair(a,b);
    }
    sort(dat.begin(),dat.end());
    ll ans=0,now=0;
    rep(i,n){
        while(now!=m&&dat[i].second!=0){
            dat[i].second--;
            ans+=dat[i].first;
            now++;
        }
    }
    cout<<ans<<endl;
}