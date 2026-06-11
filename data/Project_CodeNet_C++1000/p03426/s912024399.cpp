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
    ll h,w,d;
    cin >> h >> w >> d;
    ll grid[h][w] = {};
    P pos[h*w] = {};
    
    rep(i,0,h) rep(j,0,w){
        cin >> grid[i][j];
        grid[i][j]--;
        pos[grid[i][j]] = P(i,j);
    }

    ll memo[h*w] = {};
    rep(i,0,d){
        ll temp = i+d;
        while(temp < h*w){
            memo[temp] = memo[temp - d] + abs(pos[temp].fs - pos[temp-d].fs) + abs(pos[temp].sc - pos[temp-d].sc);
            temp += d;
        }
    }
    ll q,r,l;
    cin >> q;
    rep(i,0,q){
        cin >> l >> r;
        cout << memo[r-1] - memo[l-1] << endl;
    }

    return 0;
}
