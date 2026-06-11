#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
using namespace std;
using ll=long long;
using P =pair<int,int>;

int main(){

    int n,m;cin>>n>>m;
    vector<vector<int>>s(m);
    rep(i,m){
        int k;cin>>k;
        s[i].resize(k);
        rep(j,k){
            cin>>s[i][j];
            --s[i][j];
        }
    }
    vector<int>p(m);
    rep(i,m)cin>>p[i];
    int ans=0;
    for(int i=0;i<(1<<n);i++){
        bool ok=true;
        rep(j,m){
            int count=0;
            for(int id:s[j]){
                if((i>>id)&1)count++;
            }
            if(count%2!=p[j])ok=false;
        }
        if(ok)ans++;
    }
    cout<<ans << endl;
}