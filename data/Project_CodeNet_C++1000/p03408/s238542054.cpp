#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (int)(n); i ++)
#define irep(i,n) for (int i = (int)(n) - 1;i >= 0;--i)
using namespace std;
using ll = long long;
using PL = pair<ll,ll>;
using P = pair<int,int>;
constexpr int INF = 1000000000;
constexpr long long HINF = 1000000000000000;
constexpr long long MOD = 1000000007;// = 998244353;
constexpr double EPS = 1e-4;
constexpr double PI = 3.14159265358979;

int main() {
    int N; cin >> N;
    map<string,int> mp;
    rep(i,N) {
        string s; cin >> s;
        mp[s] ++;
    }
    int M; cin >> M;
    rep(i,M) {
        string s; cin >> s;
        mp[s] --;
    }
    int ans = 0;
    for (auto &p:mp) {
        ans = max(ans,p.second);
    }
    cout << ans << '\n';
    return 0;
}