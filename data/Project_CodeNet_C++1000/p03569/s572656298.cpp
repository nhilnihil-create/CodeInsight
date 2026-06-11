#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INFLL LLONG_MAX // 9223372036854775807
#define EPS 1e-9
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
#define Init() std::ios::sync_with_stdio(false); std::cin.tie(0); std::cout<<fixed<<setprecision(15);
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    Init();
    string s; cin >> s; ll cnt = 0;

    // xを除いた文字列が回文となっていれば回文にできる
    string t = "";
    rep(i, s.size()) if(s[i] != 'x') t += s[i];

    // 回文判定
    bool ans = true;
    ll rep = t.size()/2+(t.size()%2 == 0 ? 0 : 1);
    if(!t.size()) goto LAST;
    rep(i, rep) if(t[i] != t[t.size()-1-i]) ans = false;

    // 回文にできるなら操作回数を計算
    if(ans){
        // 同じだったら回文かつxを含んでないので操作は0回
        if(s.size() != t.size()){
            // sのうち、tのrepまでの文字が出現するところまでをts,それ以降をttとする。
            ll pos = 0, tpos = 0;
            ll ocCnt = rep;
            while(ocCnt){
                if(s[pos] == t[tpos]){
                    ocCnt--;
                    tpos++;
                }
                if(ocCnt) pos++;
            }
            string ts = s.substr(0, pos);
            if(t.size()%2 == 0){
                pos++;
                while(s[pos] == 'x') pos++;
            }
            string tt = s.substr(pos+1);
            reverse(all(tt));
            ll tsPos = 0, ttPos = 0;
            while(tsPos < ts.size() || ttPos < tt.size()){
                // どちらかが終端にたどり着いていたら
                if(tsPos == ts.size()){
                    ttPos++, cnt++;
                    continue;
                }
                if(ttPos == tt.size()){
                    tsPos++, cnt++;
                    continue;
                }
                if(ts[tsPos] != tt[ttPos]){
                    cnt++;
                    (ts[tsPos] == 'x') ? tsPos++ : ttPos++;
                }
                else tsPos++, ttPos++;
            }
        }
    }
LAST:
    cout << (ans ? cnt : -1) << endl;
}