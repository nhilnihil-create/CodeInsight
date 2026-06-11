#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n; cin>>n;
    vector<int>d(n);
    map<int,int>mp;
    rep(i,n){
        cin>>d[i];
        mp[d[i]]++;
    }
    int m; cin>>m;
    vector<int>t(m);
    bool ok=true;
    rep(i,m){
        cin>>t[i];
        mp[t[i]]--;
        if(mp[t[i]]<0){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}
