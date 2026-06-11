#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n,m;
    cin>>n;
    map<string,int>s;
    string S;
    rep(i,n){
        cin>>S;
        s[S]++;
    }
    cin>>m;
    rep(i,m){
        cin>>S;
        s[S]--;
    }
    int ans=0;
    for(auto i:s){
        ans=max(ans,i.second);
    }
    cout<<ans<<endl;

    return 0;
}
