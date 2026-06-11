#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

ll dp[100][2];
int main() {
    int n;
    ll k;
    cin >> n >> k;
    vector<ll>a(n);
    rep(i,n) cin >> a[i];
    for(int i = 0;i<100;i++) {
        for(int j = 0;j<2;j++) {
            dp[i][j] = -1;
        }
    }
    dp[0][0] = 0;
    for(int i = 0;i<50;i++) {
        ll mask = 1LL <<(50-1-i);
        int cnt = 0;
        rep(i,n) if(a[i]&mask) cnt++;
        ll cost0 = mask*cnt;
        ll cost1 = mask*(n-cnt);
        // cout << cost0 << " " << cost1 << endl;
        if(dp[i][1] != -1) {
            chmax(dp[i+1][1],dp[i][1] + max(cost0,cost1));
        }
        if(dp[i][0] != -1) {
            if(k&mask) {
                chmax(dp[i+1][1],dp[i][0]+cost0);
            }
        }
        if(dp[i][0] != -1) {
            if(k & mask) chmax(dp[i+1][0],dp[i][0]+cost1);
            else chmax(dp[i+1][0],dp[i][0]+cost0);
        }
        // cout << dp[i][0] << " " << dp[i][1] << endl;
    }
    cout << max(dp[50][0],dp[50][1]) << endl;
}
