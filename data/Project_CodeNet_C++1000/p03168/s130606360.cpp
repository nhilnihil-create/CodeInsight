#include <bits/stdc++.h>
#define nl "\n"
#define pb push_back
#define E esit(0)
#define all(v) v.begin(),v.end()
using namespace std;
using ll=long long;
const int N=1e5+5;
const int INF=1e9+7;

double dp[N];

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    dp[0]=1;
    for (int cnt=1;cnt<=n;cnt++) {
        double p;
        cin>>p;
        for (int i=cnt;i>=0;i--) {
            dp[i]=dp[i-1]*p+dp[i]*(1.0-p);
        }
    }
    double ans;
    for (int i=0;i<=n;i++) {
        int j=n-i;
        if (i>j) {
            ans+=dp[i];
        }
    }
    cout<<fixed<<setprecision(20)<<ans;
    return 0;
}