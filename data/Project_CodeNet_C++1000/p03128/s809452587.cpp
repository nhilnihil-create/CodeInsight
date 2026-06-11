#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(ll)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr ll MOD = 1e12;
constexpr double PI = 3.14159265358979323846;
vector<int> cnt = {0,2,5,5,4,5,6,3,7,6};

struct usednum{
    int used[10] = {0};
    int sum = 0;
};

int main(){
    int n,m;
    cin >> n >> m ;
    vector<int> a(m);
    rep(i,m) cin >> a[i];
    sort(a.begin(),a.end(),greater<int>());

    vector<usednum> dp(n+1);
    for(int i=1;i<=n;i++){
        for(int j=0;j<m;j++){
            if(i - cnt[a[j]] < 0) continue;
            if(i - cnt[a[j]] > 0 && dp[i-cnt[a[j]]].sum == 0) continue;
            if(dp[i].sum < dp[i-cnt[a[j]]].sum + 1){
                dp[i] = dp[i-cnt[a[j]]];
                dp[i].used[a[j]] ++;
                ++ dp[i].sum;
            }else if(dp[i].sum == dp[i-cnt[a[j]]].sum + 1){
                dp[i-cnt[a[j]]].used[a[j]] ++;
                rep(k,m){
                    if(dp[i].used[a[k]] < dp[i-cnt[a[j]]].used[a[k]]){
                        dp[i] = dp[i-cnt[a[j]]];
                        ++ dp[i].sum;
                        break;
                    }else if(dp[i].used[a[k]] > dp[i-cnt[a[j]]].used[a[k]]){
                        break;
                    }
                }
                dp[i-cnt[a[j]]].used[a[j]] --;
            }
        }
    }
   

    string ans;
    rep(i,m){
        rep(j,dp[n].used[a[i]]){
            ans += (char)(a[i] + '0');
        }
    }
    cout << ans << endl;

    return 0;
}