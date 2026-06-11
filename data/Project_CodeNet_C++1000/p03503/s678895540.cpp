#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    int ans=-INT_MAX;
    vector<int>f(n,0);
    vector<vector<int>>p(n,vector<int>(11));
    rep(i,n){
        rep(j,10){
            int x; cin>>x;
            f[i]+=x*pow(2,j);
        }
    }
    rep(i,n)rep(j,11){
        cin>>p[i][j];
    }
    for(int bit=1; bit<(1<<10); ++bit){
        int sum=0;
        rep(i,n){
            sum+=p[i][__builtin_popcount(f[i]&bit)];
        }
        ans=max(ans,sum);
    }
    cout<<ans<<endl;
    return 0;
}