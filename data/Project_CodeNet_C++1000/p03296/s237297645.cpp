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
    int n;
    cin >> n;
    vector<int> a(n,0);
    rep(i,n)cin >> a[i];
    ll res = 0;
    rep(i,n-1){
        if(a[i] == 0)continue;
        if(a[i] == a[i+1]){
            a[i+1] = 0;
            res++;
            continue;
        }
    }
    cout << res << endl;
    return 0;
}