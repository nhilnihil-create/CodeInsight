#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pp;
typedef tree<pp,null_type,less_equal<pp>,rb_tree_tag,tree_order_statistics_node_update> super_set;

#define x1 dfds
#define y1 dsfdsfe
#define pb push_back
#define forn(i,n) for(ll i = 1;i<=n;++i)
#define fi first
#define sc second
#define endl '\n'
#define po(x) (1ll<<x)
#define log sdfdsfdsf

const ll DIM = 300+7;
const ll MOD = 1e9+123;
const ll M1 = 1e9+7;
const ll INF = 1E17;
const ld eps = 0.00000000000001;
const ld PI = 3.14159265358979323846;
int getInt(int a = 0, int b = INT_MAX){
	static mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	return uniform_int_distribution <int> (a, b)(rng);
}
const ll MAXN = 1E9;
ld dp[DIM][DIM][DIM];
ll vis[DIM][DIM][DIM];
struct node{
    ll fi,sc,th;
};
const bool operator==(const node &a,const node &b){
    return a.fi==b.fi && a.sc==b.sc && a.th==b.th;
}
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    ll n;
    cin>>n;
    ll cnt[3];
    cnt[0] = cnt[1] = cnt[2] = 0;
    forn(i,n){
        ll x;
        cin>>x;
        cnt[x-1]++;
    }
    dp[cnt[0]][cnt[1]][cnt[2]] = 1;
    queue<node> Q;
    Q.push({cnt[0],cnt[1],cnt[2]});
    ld res = 0.0;
    while(!Q.empty()){
        node t = Q.front();
        Q.pop();
        if (t==node{0,0,0})break;
        ld prob = dp[t.fi][t.sc][t.th];
        ld mprb = ld(n-t.fi-t.sc-t.th)/n;
        ld bp = prob;
        while(prob>eps){
            res+=prob;
            prob*=mprb;
        }
        ll su = t.fi+t.sc+t.th;

        prob = ld(t.fi)*bp/su;

        if (t.fi>0){
            dp[t.fi-1][t.sc][t.th]+=prob;
            if (vis[t.fi-1][t.sc][t.th]==0){
                vis[t.fi-1][t.sc][t.th] = 1;
                Q.push({t.fi-1,t.sc,t.th});
            }
        }
        prob = ld(t.sc)*bp/su;
        if (t.sc>0){
            dp[t.fi+1][t.sc-1][t.th]+=prob;
            if (vis[t.fi+1][t.sc-1][t.th]==0){
                Q.push({t.fi+1,t.sc-1,t.th});
                vis[t.fi+1][t.sc-1][t.th] = 1;
            }
        }
        prob = ld(t.th)*bp/su;
        if (t.th>0){
            dp[t.fi][t.sc+1][t.th-1]+=prob;
            if (vis[t.fi][t.sc+1][t.th-1]==0){
                vis[t.fi][t.sc+1][t.th-1] = 1;
                Q.push({t.fi,t.sc+1,t.th-1});
            }
        }
    }
    cout<<fixed<<setprecision(10)<<res<<endl;
    return 0;
}
