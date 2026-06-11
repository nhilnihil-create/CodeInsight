#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)
#define _rep(i,ini,n) for(int i=ini;i>=n;i--)
#define ToEnd(a) a.begin(),a.end()
uint64_t MOD=1000000007;

int main(){
    int N,M; cin>>N>>M;
    map<int,set<pair<int,int>>> mp;
    rep(m,0,M){
        int p,y; cin>>p>>y;
        mp[p].insert(make_pair(y,m));
    }

    vector<pair<int,int>> ans(M);
    for(auto m:mp){
        int i=0;
        for(auto s:m.second){
            i++;
            ans.at(s.second)=make_pair(m.first,i);
        }
    }

    for(auto a:ans){
        cout<<setfill('0')<<right<<setw(6)<<a.first;
        cout<<setfill('0')<<right<<setw(6)<<a.second<<endl;;
    }
}