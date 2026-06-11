#include <bits/stdc++.h>
#define ll long long
#define MODV 1000000007
#define INF INT_MAX // 2147483647
#define INFLL LLONG_MAX // 9223372036854775807
#define rep(i, n) for(ll i=0, i##_len=(ll)(n); i<i##_len; i++)
#define repf(i, n) for(ll i=1, i##_len=(ll)(n+1); i<i##_len; i++)
#define per(i, n) for(ll i=((ll)(n))-1; i>=0; i--)
#define perf(i, n) for(ll i=((ll)(n)); i>0; i--)
#define all(v) v.begin(), v.end()
#define endl "\n"
#define vi vector<ll>
#define vvi vector<vector<ll>>
#define Yes() cout << "Yes" << endl
#define YES() cout << "YES" << endl
#define No() cout << "No" << endl
#define NO() cout << "NO" << endl
template<class T>bool chmax(T &a, const T &b){ if(a<b){ a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b){ if(b<a){ a=b; return 1; } return 0; }
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(10);
    
    // 入力
    string s, t; cin >> s >> t;

    // アルファベット変換表の初期化
    //map<char, char> repp;
    map<char, char> rept;
    for(ll i=(ll)'a'; i<=(ll)'z'; i++){
        rept[(char)i] = (char)i;
        //repp[(char)i] = (char)i;
    }
    
    // SとTを先頭から1文字ずつチェック
    ll s_size = s.size();
    for(ll i=0; i<s_size; i++){
        // 不一致があれば変換表を更新
        if(rept[s[i]] != t[i]){
            char changeAlp = rept[t[i]];
            while(rept[changeAlp] != t[i]) changeAlp = rept[changeAlp];
            char tmp = rept[s[i]];
            rept[s[i]] = t[i];
            rept[changeAlp] = tmp;
        }
    }

    // 変換表にもとづきSを変換
    string ans = "";
    for(ll i=0; i<s_size; i++) ans += rept[s[i]];

    // 結果の出力
    (ans == t) ? Yes() : No();
}