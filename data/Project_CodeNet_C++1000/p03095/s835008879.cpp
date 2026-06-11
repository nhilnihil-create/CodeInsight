#include <bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
const int INF = 2147483647;//int max
const int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    ll n;
    string s;
    cin >> n >> s;
    unordered_map<char,int> um;
    rep(i,n){
        um[s[i]]++;
    }
    ll ans = 1;
    for(auto au : um){
        ans *= au.second+1;
        ans%=MOD;
    }
    cout << ans%MOD-1 << endl;
    return 0;
}
/*
やっほい！
　　　　　　　やほほい！
　　　　+　　 　*
　　　 ∧∧　　. ∧∞∧　*
*　ヽ(=´ω｀)人(´ω｀*)ﾉ
　.～（ O x.） （ 　 O)～　+
。*　 　∪　　　　∪
*/