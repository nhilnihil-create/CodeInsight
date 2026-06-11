#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define rng(a) a.begin(),a.end()
using namespace std;
typedef long long int ll;
typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<P> vp;
#define dame { puts("-1"); return 0;}
#define yn {puts("Yes");}else{puts("No");}
#define MAX_N 200005

int main() {
    ll n,k;
    cin >> n >> k;
    ll a[n];
    ll b[n];
    rep(i,n)cin >> a[i] >> b[i];

    int count = 0;
    ll k_ = k;
    rep(i,30){
        if(k_ % 2 == 1)count++;
        k_ /= 2;
    }
    ll f[count + 1][30];
    rep(i,count+1){
        k_ = k;
        if(i == 0){
            rep(j,30){
                f[i][j] = k_ % 2;
                k_ /= 2;
            }
        }else{
            rep(j,30){
                f[i][j] = k_ % 2;
                k_ /= 2;
            }
            int count_ = 0;
            drep(j,30){
                if(count_ == i){
                    f[i][j] = 1;
                }else{
                    if(f[i][j] == 1){
                        count_++;
                        if(count_ == i){
                            f[i][j] = 0;
                        }
                    }
                }
            }
        }
    }
    ll ans[count + 1] = {};


    rep(i,n){
        rep(j,count+1){
            int flag = 0;
            ll a_ = a[i];
            rep(l,30){
                if(f[j][l] < (a_%2)){
                    flag = 1;
                    break;
                }
                a_ /= 2;
            }
            if(flag == 0){
                ans[j] += b[i];
            }
        }
    }

    ll ans2 = 0;
    rep(i,count + 1){
        ans2 = max(ans2, ans[i]);
    }
    cout << ans2 << endl;
    return 0;
}
 
 
