#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=unsigned long long;
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    //vector<int> cnt(m+1,0);
    map<int,int> cnt;
    rep(i,n){
        int k;
        cin>>k;
        rep(i,k){
            int a;
            cin>>a;
            cnt[a]++;
        }
    }

    int ans=0;
    /*for(int i=1;i<=m;i++){
        if(cnt[i]==n) ans++;
    }*/
    for(auto iter=cnt.begin();iter!=cnt.end();iter++){
        if(iter->second==n) ans++;
    }
    cout<<ans<<"\n";
    return 0;
}