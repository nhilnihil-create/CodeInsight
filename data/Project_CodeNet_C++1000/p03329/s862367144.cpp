#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

void chmin(int &a, int b){a = min(a, b);}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n, m = 100000;
    cin >> n;
    vector<int> dp(n+1, m);
    dp[0] = 0;
    for(int i=0;i<n;i++){
    	chmin(dp[i+1], dp[i] + 1);
    	for(int j=6;j<m;j*=6) if(j + i <= n) chmin(dp[i+j], dp[i] + 1);
    	for(int j=9;j<m;j*=9) if(j + i <= n) chmin(dp[i+j], dp[i] + 1);
    }
    cout << dp[n] << endl;
    return 0;
}
