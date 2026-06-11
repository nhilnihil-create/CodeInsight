#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define put(i) cout<<fixed<<i<<endl
using namespace std;
using ll = long long;

int main(){
    ll n; cin >> n;
    string s; cin >> s;

    ll le, lw, re, rw, ans = 1e8;
    le = lw = re = lw = 0;

    for(int i = 0; i < n; i++){
        if(s[i] == 'E') re++;
        else rw++;
    }

    for(int i = 0; i <= n; i++){
        ans = min(ans, lw + re);
        if(i == n) break;
        if(s[i] == 'E'){
            re--;
            le++;
        }else{
            rw--;
            lw++;
        }
    }

    put(ans);
}