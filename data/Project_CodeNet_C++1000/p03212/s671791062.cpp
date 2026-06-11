#include <bits/stdc++.h>
typedef long long ll;
#define rep(i,a,n) for(ll i = a;i < n;i++)
#define rrep(i,a,n) for(ll i = n; i >= a;i--)
#define index_check(i,n) if(i > n-1 || i < 0) continue; 
#define LINF 1e18
#define INF 1e9
using namespace std;

#define fs first
#define sc second

using P = pair<ll,ll>;
using Pll = pair<P,ll>;
using PQ = priority_queue<P,vector<P>,greater<P>>;

const ll MOD = 1e9+7;
ll digit_num,ans,n;

void dfs(ll k,ll num){
    if(k > digit_num) return;

    if(k >= 3){
        if(num <= n){
            ll memo[3] = {},temp = num;
            while(num){
                if(num % 10 == 3) memo[0] = 1;
                else if(num % 10 == 5) memo[1] = 1;
                else memo[2] = 1;
                num /= 10;
            }
            if(memo[0] && memo[1] && memo[2]){
                ans++;
            }
            num = temp;
        }
        
    }

    dfs(k+1,num*10+7);
    dfs(k+1,num*10+5);
    dfs(k+1,num*10+3);

    return;
}

signed main(){
    cin >> n;
    digit_num = (ll)(log10(n)+1.0);

    dfs(0,0);
 
    cout << ans << endl;
    return 0;
}
