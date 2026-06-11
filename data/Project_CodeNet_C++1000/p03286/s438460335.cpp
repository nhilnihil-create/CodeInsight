#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000100010001000100LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define rept(i, j, n) for(int i=(j); i<(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }



int main(){ 
    ll n; cin >> n;
    ll Min = 0, Max = 0; int cnt;
    rep(i, 50){
        ll num = pow(-2, i);
        if(num>0) Max += num; else Min += num;
        if(n >= Min && n <= Max){
            cnt = i;
            break;
        }
    }
    string res;
    for(int i=cnt; i>=0; i--){
        ll num = pow(-2, i);
        if(num>0)Max-=num; else Min-=num;
        if(n >= Min && n <= Max) res.push_back('0');
        else{
            res.push_back('1');
            n -= num;
        }
    }
    cout << res << ln;
}