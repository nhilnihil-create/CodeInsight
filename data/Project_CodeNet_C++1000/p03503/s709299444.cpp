#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main() {
    int n;
    cin>>n;
    int f[n][10];
    rep(i,n){
        rep(j,10){
            cin>>f[i][j];
        }
    }
    int p[n][11];
    rep(i,n){
        rep(j,11){
            cin>>p[i][j];
        }
    }

    ll ans=-1LL<<60;
    for(int bit=1;bit<(1<<10);bit++){
        ll tmp=0;
        rep(i,n){
            int cnt=0;
            rep(j,10){
                if(f[i][j]==1 && (bit & (1<<j))) cnt++;
            }
            tmp+=p[i][cnt];
        }
        ans=max(ans,tmp);
    }

    cout<<ans<<endl;
}

