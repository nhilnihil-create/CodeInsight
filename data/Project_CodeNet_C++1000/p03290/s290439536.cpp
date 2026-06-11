//vec[i]の範囲外エラー表示
#define _GLIBCXX_DEBUG
//includeとusing
#include <bits/stdc++.h>
using namespace std;
//型名省略
using ll = long long;
using st = string;
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
template<typename T> T input() {T x; cin >> x; return x;}
//正誤判定
void Yes(bool ans){cout << (ans? "Yes" : "No") << endl;}
void YES(bool ans){cout << (ans? "YES" : "NO") << endl;}
//最大値・最小値
template <typename T> bool chmax(T &a, const T& b) {if(a < b) {a = b; return true;} return false;}
template <typename T> bool chmin(T &a, const T& b) {if(a > b) {a = b; return true;} return false;}
//最大公約数
ll gcd(ll a,ll b){if(a<b)swap(a,b); if(a%b==0)return b; return gcd(b,a%b);}
//最小公倍数
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
//n乗の余り
ll modPow(ll x,ll n,ll mod){if(n==0)return 1; if(n%2==0)return modPow(x*x,n/2,mod)%mod; return x%mod*modPow(x,n-1,mod)%mod;}


/*------------------------------------------------*/

//main関数
int main() {
    ll d, g; cin >> d >> g;
    g /= 100;
    vl p(d), c(d);
    rep(i,d) {
        cin >> p[i] >> c[i];
        c[i] /= 100;
    }

    ll ans = INF;
    rep(tmp, 1<<d){
        bitset<16> comp(tmp); //コンプリートするかどうか
        ll count = 0, score = 0, noncomp = 0;
        rep(i,d){
            if(comp.test(i)){
                count += p[i];
                score += p[i] * (i + 1) + c[i];
            }
            else{
                noncomp = i;
            }
        }
        ll dis = (g - score + (noncomp + 1) - 1) / (noncomp + 1);
        if(dis < p[noncomp] && score < g){
            count += dis;
            score += dis * (noncomp + 1);
        }
        if(score >= g && ans > count){
            ans = count;
        }
    }
    cout << ans << endl;
}

