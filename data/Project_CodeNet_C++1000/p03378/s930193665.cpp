#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>

int main(){
    ll N, M, X;
    cin >> N >> M >> X;
    VL a(M);
    rep(i,0,M)cin>>a[i];
    
    ll ans=0;
    ll cnta=0, cntb=0;
    for(ll i=X; i<N; i++){
        rep(j,0,M){
            if(a[j]==i)cnta++;
        }
    }
    for(ll i=X; i>=0; i--){
        rep(j,0,M){
            if(a[j]==i)cntb++;
        }
    }
    ans=min(cnta,cntb);
    cout << ans << endl;
    return 0;
}