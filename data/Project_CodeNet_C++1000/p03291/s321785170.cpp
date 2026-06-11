#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;

long long modpow(long long x, long long n) {
    long long ret = 1;
    while (n > 0) {
        if (n & 1) ret = (ret * x) % MOD;  
        x = (x * x) % MOD;
        n >>= 1;  
    }
    return ret;
}

int count(string s){
    int res = 0;
    rep(i,s.size())  res += (s[i]=='?');
    return res;
}

int main(){
    vector<string> st = {"A","?","AB","A?","?B","??","ABC","A?C","?BC","??C","AB?","A??","?B?","???"};
    vector<int> p(st.size(),0);
    rep(i,st.size()) p[i] = count(st[i]);
    vector<ll> cnt(st.size(),0);

    string s;
    cin >> s;
    ll q = 0;

    rep(i,s.size()){
        q += (s[i]=='?');
        if(s[i]=='C'){
            for(int j=6;j<=9;j++){
                cnt[j] = (cnt[j-4]+cnt[j])%MOD;
            }
        }
        else if(s[i]=='?'){
            for(int j=10;j<=13;j++){
                cnt[j] = (cnt[j] + cnt[j-8])%MOD;
            }
        }

        if(s[i]=='A'){
            cnt[0] = (cnt[0] + 1)%MOD;
        }
        else if(s[i]=='?'){
            cnt[5] = (cnt[5] + cnt[1])%MOD;
            cnt[1] = (cnt[1] + 1)%MOD;
            cnt[3] = (cnt[3] + cnt[0])%MOD;
        }
        else if(s[i] == 'B'){
            cnt[2] = (cnt[2] + cnt[0])%MOD;
            cnt[4] = (cnt[4] + cnt[1])%MOD;
        }
    }
    ll ans = 0;
    vector<ll> three(4);
    rep(i,4) three[i] = modpow(3,q-i);
    for(int i=6;i<=13;i++){
        ans = (ans + (cnt[i] * three[p[i]])%MOD)%MOD;
    }
    cout << ans << endl;
    return 0;
}