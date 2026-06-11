#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define ve vector

int main(){
    string s,t;
    cin >> s >> t;
    int n = s.size();
    ve<int> s0(n),t0(n);
    ve<int> sj(26,-1),tj(26,-1);
    int cnt = 0;
    rep(i,n){
        int j = s[i]-'a';
        if(sj[j] != -1) s0[i] = sj[j];
        else{
            sj[j] = cnt;
            cnt++;
            s0[i] = sj[j];
        }
    }
    cnt = 0;
    rep(i,n){
        int j = t[i] - 'a';
        if(tj[j] != -1) t0[i] = tj[j];
        else{
            tj[j] = cnt;
            cnt++;
            t0[i] = tj[j];
        }
    }
    if(s0 == t0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}