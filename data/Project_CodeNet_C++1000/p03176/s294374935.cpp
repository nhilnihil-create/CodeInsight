#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<char,int> pci;
typedef vector<pair<int,int>> vpii;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
#define sci(a) scanf("%d",&a)
#define scii(a,b) scanf("%d %d",&a,&b)
#define sciii(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define sciiii(a,b,c,d) scanf("%d%d%d%d",&a,&b,&c,&d)
#define scl(a) scanf("%lld",&a)
#define scll(a,b) scanf("%lld %lld",&a,&b)
#define sclll(a,b,c) scanf("%lld %lld %lld",&a,&b,&c
#define scllll(a,b,c,d) scanf("%lld %lld %lld %lld",&a,&b,&c,&d)
#define print(a) printf("%d ",a)
#define println(a) printf("%d\n",a)
#define ln printf("\n")
#define pb(a) push_back(a)
#define m_p(a,b) make_pair(a,b)
#define all(a) a.begin(),a.end()
#define rep(i,s,n) for(int i=s;i<=n;i++)
#define rrep(i,e,s) for(int i=e;i>=s;i--)
#define repv(i,m) for(auto i = m.begin();i != m.end();i++)
#define FileIO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#define FastIO ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const long long INF = 4000000000000000000LL;
/************************************* Chocolate *************************************/
const int MAX = 2e5;
vll tree(MAX*4),dp(MAX+1);
void update(int node,int l,int r,int index){
    if(l > index || r < index) return;
    if(l == r){
        tree[node] = max(tree[node],dp[index]);
        return;
    }
    int mid = l + (r-l)/2;
    update(node*2+1,l,mid,index);
    update(node*2+2,mid+1,r,index);
    tree[node] = max(tree[node*2+1],tree[node*2+2]);
}
ll query(int node,int l,int r,int low,int high){
    if(low > r || high < l) return 0;
    if(low <= l && high >= r)
        return tree[node];
    int mid = l + (r-l)/2;
    ll m1 = query(node*2+1,l,mid,low,high);
    ll m2 = query(node*2+2,mid+1,r,low,high);
    return max(m1,m2);
}
int main(){
    int n;
    sci(n);
    vi h(n),b(n);
    rep(i,0,n-1){
        sci(h[i]);
    }
    rep(i,0,n-1){
        sci(b[i]);
    }
    rep(flower,0,n-1){
        ll best = query(0,0,n-1,0,h[flower]);
        dp[h[flower]] = best + b[flower];
        update(0,0,n-1,h[flower]);
    }
    ll ans = 0;
    rep(i,1,n){
        ans =max(ans,dp[i]);
    }
    cout << ans << endl;
}