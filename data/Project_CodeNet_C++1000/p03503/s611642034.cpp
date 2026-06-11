#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int f[110][10];
ll p[110][11];
int cnt[110];

int main() {
    int n;
    cin>>n;
    rep(i,n){
        rep(j,10){
            cin>>f[i][j];
        }
    }
    rep(i,n){
        rep(j,11){
            cin>>p[i][j];
        }
    }

    ll ans=-1LL<<60;
    rep(bit,1<<10){
        if(bit==0) continue;
        rep(i,n) cnt[i]=0;
        rep(i,10){
            if(bit & 1<<i){
                rep(j,n){
                    if(f[j][i]==1) cnt[j]++;
                }
            }
        }
        ll tmp=0;
        rep(i,n){
            tmp+=p[i][cnt[i]];
        }
        ans=max(ans,tmp);
    }
    
    cout<<ans<<endl;
}