#include<iostream>
#include<vector>
#include<algorithm>
#define rep(i,n) for(long long i = 0; i < n; i++)
using namespace std;
int main()
{
    long long H, W, ans = 0;
    cin>> H >> W;
    vector<vector<long long>>hw(H,vector<long long>(W));
    vector<vector<long long>>magic(10,vector<long long>(10));
    rep(i,10){
        rep(j,10) cin>>magic[i][j];
    }

    rep(i,H){
        rep(j,W) cin>>hw[i][j];
    }

    rep(k,10){
        rep(i,10){
            rep(j,10) magic[i][j] = min(magic[i][j],magic[i][k] + magic[k][j]);
        }
    }

    rep(i,H){
        rep(j,W){
            if(hw[i][j] != -1){
                ans += magic[hw[i][j]][1];
            }
        }
    }

    cout<<ans<<endl;
    return 0;
}