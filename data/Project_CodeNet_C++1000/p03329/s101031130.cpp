#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define SZ(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<(int)(n);i++)
#define rep2(i, j, n) for(int i=j;i<(int)(n);i++)
#define all(v) v.begin(), v.end()
using ll = long long;
using P = pair<int, int>;
const ll INF = 1000000LL;
int N,W;
int main(){
    int n;
    cin >> n;
    ll dp[n+1];
    rep(i, n+1) dp[i]=INF;
    dp[0]=0;
    int a=6, b=9;
    rep(i, n){
        dp[i+1] = min(dp[i+1], dp[i]+1);
        a=6;
        rep(j, 7){
            if(i+a<=n){
                dp[i+a] = min(dp[i+a], dp[i]+1);
                a*=6;
            } else {
                break;
            }
        }
        b=9;
        rep(j, 7){
            if(i+b<=n){
                dp[i+b] = min(dp[i+b], dp[i]+1);
                b*=9;
            } else {
                break;
            }
        }
    }
    cout << dp[n] << endl;
}
