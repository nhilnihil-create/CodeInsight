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
    string s; cin >> s;
    // 26種類の文字を使っていないなら、未使用文字の中で最も小さい文字を末尾に加えれば良い
    if(s.size() < 26){
        map<char, ll> cnt;
        for(char c='a'; c<='z'; c++) cnt[c] = 0;
        rep(i, s.size()) cnt[s[i]]++;
        char add = '!';
        for(auto &p: cnt) if(p.second == 0){ add = p.first; break; }
        cout << s << add << endl;
    }
    // 全ての文字を使っている場合
    else{
        // これ以上小さくすることが可能かどうか判定
        string t = "zyxwvutsrqponmlkjihgfedcba";
        if(s == t) cout << -1 << endl;
        else{
            set<char> ch;
            // 末尾から見ていき、s[i-1]<s[i]となる箇所s[i-1]を
            // 使える文字の中でs[i-1]より大きい最小の文字で上書き
            for(ll i=25; i>0; i--){
                ch.insert(s[i]);
                if(s[i-1]<s[i]){
                    char c = *ch.upper_bound(s[i-1]);
                    cout << s.substr(0, i-1) << c << endl;
                    break;
                }
            }
        }
    }
}