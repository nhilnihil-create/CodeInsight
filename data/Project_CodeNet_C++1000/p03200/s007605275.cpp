#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    string S;
    cin >> S;
    ll len = S.size();
    ll cnt_white = 0;
    rep(i,len){
        if (S[i] == 'W') cnt_white++;
    }
    ll ans = 0;
    ll ans_sub = 0;
    for (ll i = 0; i < cnt_white; i++){
        ans_sub += i;
    }
    rep(i,len){
        if (S[i] == 'W') ans += i;
    }
    cout << ans - ans_sub << endl;
}
