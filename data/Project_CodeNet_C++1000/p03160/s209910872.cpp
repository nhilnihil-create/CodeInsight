#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1e9+7
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i=0;i<n;i++) cin >> h[i];
    vector<int> dp(n);
    dp[1]=abs(h[1]-h[0]);
    for(int i=2;i<n;i++) dp[i]=min(dp[i-1]+abs(h[i]-h[i-1]),dp[i-2]+abs(h[i]-h[i-2]));
    cout << dp.back() << endl;
}