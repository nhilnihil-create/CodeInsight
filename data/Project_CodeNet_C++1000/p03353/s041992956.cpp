#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 1 << 30;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    map<string,int> m;
    string s;
    ll k;
    cin >> s >> k;
    const ll n = s.length();
    for(ll i = 0;i < n;i++){
        for(ll j = 1;j <= n;j++){
            ll len = j;
            if(i + j > n)len = s.length() -1;
            if(len > k)continue;
            m[s.substr(i,len)]++;
        }
    }
    ll cnt = 1;
    for(auto a : m){
        if(cnt == k){
            cout << a.first << "\n";
            return 0;
        }else cnt++;
    }
    return 0;
}