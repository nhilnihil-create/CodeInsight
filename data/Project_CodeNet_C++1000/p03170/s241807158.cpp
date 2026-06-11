#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

bool dp[100005];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    rep(j,k+1){
        rep(i,n){
            if(j-a[i] >= 0) dp[j] |= !dp[j-a[i]];
        }
    }
    cout << (dp[k] ? "First" : "Second") << endl;
    return 0;
}
