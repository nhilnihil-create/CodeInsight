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

using PS = pair<string,string>;
map<PS,ll> count_string(const string &a,int flag) {
    int N = a.size();
    map<PS,ll> cnt;
    rep(bit,1<<N) {
        string s,t;
        rep(i,N) {
            if ((bit>>i)&1) s += a[i];
            else t += a[i];
        }
        reverse(t.begin(),t.end());
        if (flag == 0) cnt[make_pair(s,t)] ++;
        else cnt[make_pair(t,s)] ++;
    }
    return cnt;
}

int main() {
    int N; cin >> N;
    string s; cin >> s;
    map<PS,ll> left = count_string(s.substr(0,N),0);
    map<PS,ll> right = count_string(s.substr(N,N),1);
    
    ll ans = 0;
    for (auto &p:right) {
        ans += left[p.first] * p.second;
    }
    cout << ans << '\n';
    return 0;
}