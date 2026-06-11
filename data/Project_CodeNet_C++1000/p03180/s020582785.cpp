#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

ll a[20][20];
ll dp[1LL<<20];

int main(){
    int n;
    cin >> n;
    rep(i,n)rep(j,n) cin >> a[i][j];
    rep(bit,1<<n){
        vector<int> id;
        rep(i,n){
            if(bit>>i&1) id.push_back(i);
        }
        rep(i,id.size()){
            rep(j,i){
                dp[bit] += a[id[i]][id[j]];
            }
        }
    }

    rep(bit,1<<n){
        for(int j=bit;j>0;j=(j-1)&bit){
            dp[bit] = max(dp[bit],dp[j] + dp[bit^j]);
        }
    }

    cout << dp[(1<<n)-1] << endl;
    return 0;
}
