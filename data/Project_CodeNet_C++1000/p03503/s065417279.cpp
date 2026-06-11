#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long int ll;
const int MOD=1000000007;

int main(){

    int n;cin>>n;

    int f[105][13];
    ll p[105][14];

    rep(i,n){
        rep(j,10){cin>>f[i][j];}
    }
    rep(i,n){
        rep(j,11){cin>>p[i][j];}
    }
    ll mx = -10000000010;
    for(int bit = 1;bit<(1<<10);bit++){
        vector<int> cnt(n,0);
        rep(i,10){
            if(bit&(1<<i)){
                rep(j,n){
                    if(f[j][i]==1)cnt[j]++;
                }
            }
        }
        ll sum = 0;
        rep(j,n)sum += p[j][cnt[j]];
        mx = max(mx,sum);
    }
    cout<<mx<<endl;
    
    
    return 0;
}