#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N; cin>>N;
    map<int,int> mp;
    rep(n,0,N){
        int a; cin>>a;
        mp[a]++;
    }

    int ans=0;
    for(auto m:mp){
        if(m.first>m.second) ans+=m.second;
        else ans+=m.second-m.first;
    }

    cout<<ans<<endl;
}