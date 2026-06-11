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

signed main(){
    ll n,memo = LINF,memo_i,memo_j,memo_k;
    cin >> n;
    rep(i,1,3500){
        rep(j,1,3500){
            if(4*i*j - n*j -n*i > 0 && n*i*j % (4*i*j - n*j -n*i) == 0){
                ll x = n*i*j / (4*i*j - n*j -n*i);
                
                if(4*i*j*x == (i*x+j*x+i*j)*n && memo > max(i,max(j, x))){
                    memo = max(i,max(j, x));
                    memo_i = i;
                    memo_j = j;
                    memo_k = x;
                }
            }
        }
    }

    cout << memo_i << " " << memo_j << " " << memo_k << endl;
    return 0;
}
