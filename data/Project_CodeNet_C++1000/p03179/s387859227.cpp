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

int dp[3001][3001];

void compute(string &s, int n){
    dp[n][0] = (s[n-2] == '>' ? 1 : 0);
    dp[n][1] = (s[n-2] == '<' ? 1 : 0);
    forD(i, 2, n-1){
        int total = n - i + 1;;
        forI(g, 0, total){
            if(g == 0){
                if(i == n)    continue;
                dp[i][g] = 0;
                if(s[i-2] == '<')
                    continue;
                forI(j, 1, total){
                    dp[i][g] = (dp[i][g] + dp[i+1][total-j])%mod;
                }
            }else{
                if(s[i-2] == '>')
                    dp[i][g] = (dp[i][g-1] - dp[i+1][g-1] + mod)%mod;
                else
                    dp[i][g] = (dp[i][g-1] + dp[i+1][g-1])%mod;

            }
        }
    }
}

void solve(){
    int n;  cin>>n;
    string s;   cin>>s;
    int ans=0;
    compute(s, n);
    forD(gr, 0, n-1)
        ans = (ans+dp[2][gr])%mod;
    cout<<ans;
}   

int32_t main(){
    init();
    // w(t) 
    solve();
    return 0;
}