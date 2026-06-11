#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
using Graph = vector<vector<int>>;
int main(int argc, const char * argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n;
    cin>>n;
    p p[n];
    rep(i,n){
        cin>>p[i].first;
    }
    rep(i,n){
        cin>>p[i].second;
    }
    int ans=-1e9;
    for(int bit=0;bit<(1<<n);bit++){
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(bit&(1<<i)){
                x+=p[i].first;
                y+=p[i].second;
            }
        }
        ans=max(ans,x-y);
    }
    cout<<ans<<endl;

    return 0;
}