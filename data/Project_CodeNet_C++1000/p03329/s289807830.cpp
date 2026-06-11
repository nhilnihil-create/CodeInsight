#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define per(i,n) for(int i=(n)-1; i>=0; i--)
#define chmin(a,b) a = min(a,b)
using namespace std;
using vi = vector<int>;
using vv = vector<vi>;
const int MOD = 1000000007;

int main(){
    int n;cin>>n;
    
    vector<long long> dp(n+1,MOD);
    dp[0] = 0;
    
    vi a;
    a.push_back(1);
    int b = 6;
    while(b<=n){
        a.push_back(b);
        b *= 6;
    }
    b = 9;
    while(b<=n){
        a.push_back(b);
        b *= 9;
    }
    
    sort(a.rbegin(), a.rend());
    
    rep(i,a.size()){
        for(int j=0; j+a[i]<=n; j++){
            chmin( dp[j+a[i]], dp[j]+1 );
        }
    }
    
    cout << dp[n] << endl;
    
    return 0;
}