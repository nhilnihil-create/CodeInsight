#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
using ll = long long;
using P = pair<ll, ll>;
ll GCD(ll a, ll b) { return b?GCD(b, a%b):a; }
ll LCM(ll a, ll b) { return a/GCD(a, b)*b; }

ll n, k;

int main() {
    cin >> n >> k;
    vector<ll> Avec(n, 0);
    for(int i = 0; i < n; ++i) cin >> Avec.at(i);
    sort(Avec.rbegin(), Avec.rend());

    int bit = 0;
    for(bit = 0; (1LL<<bit) <= k; ++bit);
    // cout << bit << endl;
    vector<int> bitcnt;
    for(int i = 0; i < n; ++i) {
        if(i == 0) {
            for(int bbit = 0; (1LL<<bbit) <= Avec.at(i); ++bbit) {
                if(Avec.at(i)&(1LL<<bbit)) bitcnt.emplace_back(1);
                else bitcnt.emplace_back(0);
            }
        }else {
            for(int bbit = 0; (1LL<<bbit) <= Avec.at(i); ++bbit) {
                if(Avec.at(i)&(1LL<<bbit)) bitcnt.at(bbit)++;
            }
        }
    }

    int cntlen = bitcnt.size();
    if(cntlen < bit) {
        for(int i = cntlen; i < bit; ++i) bitcnt.emplace_back(0);
    }

    reverse(bitcnt.begin(), bitcnt.end());
    // 0 2 2 2になってる

    vector< vector<ll> > dp(45, vector<ll>(2, -1));
    ll nlen = bitcnt.size();
    
    dp[0][0] = 0;
    for(ll i = 0; i < nlen; ++i) {
        ll mask = 1LL<<(nlen-i-1);
        int cnt1 = bitcnt.at(i);
        int cnt0 = n - cnt1;
        if(dp[i][1] >= 0) chmax(dp[i+1][1], dp[i][1] + mask*max(cnt1, cnt0));
        if(dp[i][0] >= 0) {
            if(k&mask) {
                chmax(dp[i+1][1], dp[i][0] + mask*cnt1);
                chmax(dp[i+1][0], dp[i][0] + mask*cnt0);
            }else {
                chmax(dp[i+1][0], dp[i][0] + mask*cnt1);
            }
        }
    }

    cout << max(dp[nlen][0], dp[nlen][1]) << endl;
}