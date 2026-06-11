//vec[i]の範囲外エラー表示
#define _GLIBCXX_DEBUG
//includeとusing
#include <bits/stdc++.h>
using namespace std;
//型名省略
using ll = long long;
using vl = vector<long long>;
using vvl = vector<vector<long long>>;
using vc = vector<char>;
using vvc = vector<vector<char>>;
using vs = vector<string>;
using pll = pair<ll, ll>;
//定数
const ll INF = 1e9;
const ll MOD = 1e9+7;
//マクロ
#define rep(i,n) for(ll i = 0; i < (ll) n; i++)
#define xrep(i,x,n) for(ll i = (ll) x; i < (ll) n; i++)
#define all(A) A.begin(), A.end()
//入力
ll llin() {ll x; cin >> x; return x;}
string stin() {string s; cin >> s; return s;}
vl vlin(ll n) {vl a(n); rep(i,n){cin >> a[i];} return a;}
//正誤判定
void Yes(bool ans){cout << (ans? "Yes" : "No") << endl;}
void YES(bool ans){cout << (ans? "YES" : "NO") << endl;}


//main関数
int main() {
    string s; cin >> s;

    rep(tmp, 1<<3){
        bitset<3> op(tmp);
        ll sum = s[0] - '0';
        string ans = "";
        ans += s[0];
        rep(i,3){
            if(op.test(i)) {
                sum += s[i + 1] - '0';
                ans += "+";
                ans += s[i + 1];
            }
            else {
                sum -= s[i + 1] - '0';
                ans += "-";
                ans += s[i + 1];
            }
        }
        if(sum == 7){
            ans += "=7";
            cout << ans << endl;
            return 0;
        }
    }
}

