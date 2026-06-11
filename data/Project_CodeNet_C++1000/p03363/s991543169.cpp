#include <bits/stdc++.h>
#define repp(i,l,r)for(long long i=(l);i<(r);i++)
#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define per(i,n) for (long long i = (n); i >= 0; --i)
const int INF = 2147483647;//int max
const long long int MOD = 1000000007;
using namespace std;
using ll = long long;
using P = pair<int,int>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//ミョ(-ω- ?)
int main() {
    ll n;
    cin >> n;
    vector<ll> a(n+1,0);
    repp(i,1,n+1){
        ll in;cin >> in;
        a[i] = a[i-1] + in;
    }
    unordered_map<ll,ll> m;
    for(auto i : a)m[i]++;
    ll res = 0;
    for(auto a : m)res += (a.second*(a.second-1))/2;
    cout << res << endl;
    return 0;
}