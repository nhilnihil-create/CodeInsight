#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, K;
    cin >> N >> K;
    string s;
    cin >> s;
    vector<ll> x;
    x.push_back(0);
    char now = s[0];
    rep(i, 1, N){
        if(s[i] != now){
            x.push_back(i);
            now = s[i];
        }
    }
    x.push_back(N);

    rep(i, 0, x.size()) cerr << x[i] << " ";
    cerr << endl;

    ll ans = 0;
    rep(i, 0, x.size()){
        ll j = x[i];
        if(s[j] == '0'){
            ll v = x[min((ll)x.size()-1, i+2*K)] - j;
            ans = max(ans, v);
        }else{
            ll v = x[min((ll)x.size()-1, i+2*K+1)] - j;
            ans = max(ans, v);
        }
    }
    cout << ans << endl;
    return 0;
}