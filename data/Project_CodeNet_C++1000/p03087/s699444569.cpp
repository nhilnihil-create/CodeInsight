#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int sum[100005];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    string s;
    cin >> n >> q >> s;
    s += "!!";
    rep(i,n-1){
        if(s[i] == 'A' && s[i+1] == 'C') ++sum[i+2];
    }
    for(int i = 1; i <= n; ++i){
        sum[i] += sum[i-1];
    }
    rep(i,q){
        int l, r;
        cin >> l >> r;
        int ans = sum[r] - sum[l];
        cout << ans << endl;
    }
    return 0;
}
