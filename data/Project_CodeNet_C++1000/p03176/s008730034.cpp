#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define F               first
#define S               second
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18 + 1
#define endl            '\n'
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
#define forI(i,a,n)     for(int i=a;i<=n;i++)
#define forD(i,a,n)     for(int i=n;i>=a;i--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
 
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> pbds;
 
void init(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}

struct flower{
    int hi, bty;
};

int compute(vector<flower> &v, int n){
    vi dp(n+1);
    mii meaningful;
    dp[1] = v[1].bty;
    meaningful[v[1].hi] = dp[1];
    int ans=dp[1];

    forI(i, 2, n){
        dp[i] = v[i].bty;
        auto it = meaningful.lower_bound(v[i].hi+1);
        if(it != meaningful.begin()){
            it--;
            dp[i] += it->ss;
        }
        meaningful[v[i].hi] = dp[i];
        it = meaningful.upper_bound(v[i].hi);
        while(it != meaningful.end() && it->ss <= dp[i]){
            auto temp = it;
            temp++;
            meaningful.erase(it);
            it = temp;
        }
        ans = max(ans, dp[i]);
    }
    return ans;
}

void solve(){
    int n;  cin>>n;
    vector<flower> v(n+1);
    forI(i, 1, n)   cin>>v[i].hi;  forI(i, 1, n)   cin>>v[i].bty;

    cout<<compute(v, n);
}   

int32_t main(){
    init();
    // w(t) 
    solve();
    return 0;
}