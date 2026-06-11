#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>

int main(){
    ll N, D, X;
    cin >> N >> D >> X;
    VL a(N+1);
    rep(i,1,N+1) cin>>a[i];
    
    ll ans=X;
    rep(i,1,N+1){
        ll day=1;
        rep(j,1,D+1){
            if(j==day){
                ans++;
                day+=a[i];
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}