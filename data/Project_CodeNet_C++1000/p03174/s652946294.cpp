#include <bits/stdc++.h>
/**
AHMAD;HASSAN;SAEED
*/
using namespace std;
int n;
long long rm=1e9+7;
int cnt=0;
vector<long long>dp((1<<22),-1ll);
vector<vector<int> >mtx2;
long long slv(int vis=(1<<(n))-1){
    cnt++;
    long long ret=0ll;
    int idx=n;
    int tm=vis;
    while(tm){
        if(tm&1)
            idx--;
        tm/=2;
    }
    if(idx==n){
        return 1ll;

    }
    if(dp[vis]!=-1ll)
        return dp[vis];
    for(int i=0;i<n;i++){
        if(mtx2[idx][i]&&(vis&((1<<i)))){
            ret+=slv(vis&(~(1<<i)));
            ret%=rm;
        }

    }
    return dp[vis]=ret;
}


int main()
{

    cin>>n;
    vector<vector<int> >mtx(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>mtx[i][j];
        }
    }
    mtx2=mtx;
    cout<<slv()<<'\n';
/**
4
1 1 1 1
1 1 1 1
1 1 1 1
1 1 1 1
*/
    return 0;
}
