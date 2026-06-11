#include <bits/stdc++.h>
#define ll          long long int
#define uu          first
#define vv          second
#define pii         pair<int,int>
#define pll         pair<ll,ll>
#define INF         1e18
#define fastRead    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;

const ll MOD = 1e9 + 7;
const int MAX = 1e6+ 6;

ll tree[4*MAX];

void update(int node, int l, int r, int id,ll val) {
    
    if(l > id || r< id) return ;
    if(l == r) {
        tree[node] = val;
        return;
    }
    int mid = (l+r)/2;
    update(node<<1, l , mid, id, val);
    update(node<<1|1, mid+1, r, id, val);
    tree[node] = max(tree[node<<1], tree[node<<1|1]);
}

ll query(int node, int l, int r,int frm, int to) {
    
    if( l > to || r < frm || l > r) return 0;
    if(l >=frm && r<= to) return tree[node];
    int mid = (l+r)/2;
    ll q1 = query(node<<1, l, mid, frm, to);
    ll q2 = query(node<<1|1, mid+1 ,r ,frm, to);
    return max(q1, q2);
}


int main()
{
    int n;
    cin>>n;
    vector<ll>h(n+1), a(n+1), dp(n+1);
    for(int i =1; i <=n ; i++ ) cin>>h[i];
    for(int i =1; i <=n ; i++ ) cin>>a[i];
    
    for(int i =1; i <=n ; i++ ) {
        
        ll ret = query(1, 1, n, 1, h[i]-1);
        dp[i] = ret + a[i];
        update(1, 1, n, h[i], dp[i]);
    }
    cout<<query(1, 1, n, 1, n)<<'\n';
    return 0;
}