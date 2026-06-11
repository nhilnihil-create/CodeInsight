#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, K;
    cin >> N >> K;
    
    ll ans=1;
    rep(i,0,N){
        ans=min(ans*2, ans+K);
    }
    cout << ans << endl;
    return 0;
}
