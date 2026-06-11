#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define REP(i,n) for (int i = 1; i < (int)(n); i++)
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define debug(var) do{cout << #var << " : "; view(var);}while(0)
template<class T> bool chmin(T &a, T b) {if(a>b) {a=b;return 1;}return 0;}
template<class T> bool chmax(T &a, T b) {if(a<b) {a=b;return 1;}return 0;}
using namespace std;
template<class T> void view(T e) {cout << e << endl;}
template<class T> void view(const vector<T> &v) {for(const auto &e : v){cout << e << " ";} cout << endl;}
template<class T> void view(const vector<vector<T>> &vv) {for(const auto &v : vv){view(v);}}
using vint = vector<int>;
using vvint = vector<vector<int>>;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<int,int>;
const int inf = 1e9;
const ll inf_l = 1e18;
const int MAX = 1e5;

//最大公約数と最小公倍数
ll gcd(ll a, ll b) {return(b?gcd(b,a%b):a);}

int main() {
    int n; cin >> n;
    if (n == 3) {cout << 2 << " " << 5 << " " << 63 << endl; return 0;}
    if (n == 4) {cout << 2 << " " << 5 << " " << 20 << " " << 63 << endl; return 0;}
    if (n == 5) {cout << 2 << " " << 5 << " " << 20 << " " << 30 << " " << 63 << endl; return 0;}
    int sum = 0;
    vint ans;
    for (int i = 2; i <= 30000; i++) {
        if (n == 0) break;
        if (i % 2 != 0 && i % 3 != 0) continue;
        ans.push_back(i);
        sum += i;
        n--;
    }
    int rem = sum % 6;
    if (rem == 2) {
        rep(i,ans.size()) {
            if (ans[i] == 8) {ans.erase(ans.begin()+i); break;}
        }
        int x = ans.back() + 6 - (ans.back()%6);
        ans.push_back(x);
    }
    if (rem == 3) {
        rep(i,ans.size()) {
            if (ans[i] == 9) {ans.erase(ans.begin()+i); break;}
        }
        int x = ans.back() + 6 - (ans.back()%6);
        ans.push_back(x);
    }
    if (rem == 5) {
        rep(i,ans.size()) {
            if (ans[i] == 9) {ans.erase(ans.begin()+i); break;}
        }
        for (int i = ans.back()+1;;i++) {
            if (i % 6 == 4) {
                ans.push_back(i);
                break;
            }
        }
    }
    rep(i,ans.size()) cout << ans[i] << " ";
}