#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <assert.h>
#include <queue>
#include <string.h>
#include <string>
#include <set>
#include <memory.h>
#include <functional>
#include <bitset>
using namespace std;
#define ll long long

const int N = 2e5+15;

int a[N];

ll sum[N];

pair<ll,ll> dp[N][2];
void solve() {
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i) {
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;++i) {
        sum[i] = sum[i-1] + a[i];
    }
    int pos = n;
    for(int i=n;i>=1;--i) {
        ll cur = sum[n] - sum[i-1];
        while(i<=pos-1 && (sum[pos-1] - sum[i-1])*2>=cur) {
            --pos;
        }
        for(int j=-1;j<=0;++j) {
            dp[i][j+1] = make_pair(sum[pos+j] - sum[i-1], sum[n] - sum[pos+j]);
        }
    }
    pos = 1;
    ll ret = 4e18;
    for(int i=2;i<=n-2;++i) {
        while(pos+1<=i && (sum[pos+1]*2 <= sum[i]) ) {
            ++pos;
        }
        for(int j=0;j<=1;++j) {
            dp[i][j] = make_pair(sum[i] - sum[pos+j] , sum[pos+j]);
        }
        for(int x=0;x<2;++x) {
            for(int y=0;y<2;++y) {
                ll maxi = max( max(dp[i][x].first,dp[i][x].second),max(dp[i+1][y].first,dp[i+1][y].second));
                ll mini = min( min(dp[i][x].first,dp[i][x].second),min(dp[i+1][y].first,dp[i+1][y].second));
                ret = min(ret, maxi - mini);
            }
        }
    }
    cout<<ret<<endl;
}

int main() {
    //freopen("/Users/gotop/Documents/ps_practice/ps_practice/input.txt", "r", stdin);
    solve();
}
