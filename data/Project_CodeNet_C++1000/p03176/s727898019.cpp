#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <set>
using namespace std;
typedef long long LL;
const int N = 2e5+100;

LL dp[N];
LL a[N],h[N];
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int i = 1; i<=n; i++) cin>>h[i];
    for(int i = 1; i<=n; i++) cin>>a[i];
    
    set<pair<LL,LL>> s;
    s.insert({0,0});
    for(int i = 1; i<=n; i++){
        auto p = prev(s.lower_bound({h[i],0}));
        dp[i] = p->second + a[i];
        while(1){
            auto q = s.lower_bound({h[i],0});
            if(q != s.end() && q->second <= dp[i])
                s.erase(q);
            else 
                break;
        }
        s.insert({h[i],dp[i]});
    }
    
    LL ans = 0;
    for(int i = 1; i<=n; i++) ans = max(ans,dp[i]);
    cout<<ans;
    return 0;
}