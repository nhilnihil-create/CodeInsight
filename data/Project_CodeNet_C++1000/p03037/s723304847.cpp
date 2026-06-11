#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>

int main(){
    ll N, M;
    cin >> N >> M;
    VL l(N,0), r(N,0);
    ll L, R;
    rep(i,0,M){
        cin >> L >> R;
        L--; R--;
        l[L]++; r[R]++;
    }
    rep(i,0,N) if(l[i] > 0) L = i;
    rep(i,0,N) if(r[i] > 0){R = i; break;}
    
    ll ans = 0;
    rep(i,L,R+1) ans++;
    cout << ans << endl;
    return 0;
}