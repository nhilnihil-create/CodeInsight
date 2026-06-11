#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N;
    string S;
    ll mod = 1e9+7;
    cin >> N >> S;
    vector<ll> c(26,1);
    for(auto ss : S){
        c[ss-'a']++;
        c[ss-'a'] %= mod;
    }
    ll ans = 1;
    for(auto cc : c){
        ans *= cc;
        ans %= mod;
    }
    ans--;
    cout << ans << endl;
    return 0;
}