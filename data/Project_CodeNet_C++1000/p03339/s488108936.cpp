#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(long long N, std::string S){
    ll cnt_e = 0;
    for(ll i = 0; i < N; ++i) if(S[i] == 'E') cnt_e++;
    //cout << cnt_e << endl;
    vector<ll> cnt(N, cnt_e);
    for(ll i = 0; i < N; ++i){
        if(i > 0) cnt[i] = cnt[i-1];
        if(S[i] == 'E') cnt[i]--;
        if(i > 0 && S[i-1] == 'W') cnt[i]++;
    }
    //for(auto i : cnt) cout << i << " ";
    //cout << endl;
    ll ans = 1e18;
    for(ll i = 0; i < N; ++i) ans = min(ans, cnt[i]);
    cout << ans << endl;
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::string S;
    std::cin >> S;
    solve(N, S);
    return 0;
}
