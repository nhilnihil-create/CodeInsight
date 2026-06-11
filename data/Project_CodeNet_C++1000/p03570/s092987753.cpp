#include <bits/stdc++.h>

//#define DEBUG 1

#define for0(i,n) for (int i=0; i<n; i++)
#define iter(c) for(auto it=c.begin(); it!=c.end(); it++)
#define iter2(c) for(auto it2=c.begin(); it2!=c.end(); it2++)
#define pb push_back
#define ms(a,z) memset(a,z,sizeof(a));
#define mp make_pair
#define X first
#define Y second
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define all(a) a.begin(),a.end()
#define sz(x) (int)(x).size()
#define pmod(x,m) (((x)%(m)+m)%m)
#ifdef int
#define read(x) scanf("%lld",&x);
#else
#define read(x) scanf("%d",&x);
#endif

#ifdef DEBUG
#define nl cout<<"\n";
#define pr(x) cout<<(x)<<" ";
#define prl(x) cout<<#x " = "<<x<<endl;
#define prp(x) cout<<"("<<(x).first<<" "<<(x).second<<") ";
#define printv(v) {for(int _=0; _<sz(v); _++) cout<<v[_]<<" "; cout<<"\n";}
#define printa(a,s) {for (int _=0; _<s; _++) cout<<a[_]<<" "; cout<<"\n";}
#define print2D(a,m,n) {for (int _=0; _<m; _++) {for (int __=0; __<n; __++) cout<<a[_][__]<<" "; cout<<"\n";} cout<<"\n";}
#define debug cout<<"ok at line "<<__LINE__<<endl;
#else
#define nl
#define pr(x)
#define prl(x)
#define prp(x)
#define printv(v)
#define printa(a,s)
#define print2D(a,m,n)
#define debug
#endif

using namespace std;

typedef long long ll;

const int INF = 999999999;
const long long INFL = 9223372036854775807LL;
const double EPSILON = 0.00000001;
const long long MOD = 1000000007;

int mask[200005];
int best_val[(1<<26)+10];
int dp[200005];

int get_val(int i, int goal_mask)
{
    int req_mask = goal_mask ^ mask[i-1];
    if (best_val[req_mask] == INF)
        return INF;
    else 
        return best_val[req_mask]+1;
}

int32_t main()
{
    #ifdef DEBUG
    freopen("D.txt","r",stdin);
    //freopen("","w",stdout);
    #endif

    string s;
    cin >> s;
    int n = s.length();
    for0(i,(1<<26))
        best_val[i] = INF;
        
    int cur_mask = 0;
    mask[0] = 0;
    for (int i=0; i<n; i++) {
        cur_mask ^= 1<<(s[i]-'a');
        mask[i+1] = cur_mask;
    }
    
    //printa(mask,n+1);
    dp[n] = 1;
    best_val[mask[n]] = 0;
    
    for (int i=n-1; i>=1; i--) {
        best_val[mask[i]] = min(best_val[mask[i]], dp[i+1]);    
        
        int ans = get_val(i,0);
        for (int b=0; b<26; b++) {
            int res = get_val(i,1<<b);
            ans = min(ans,res);
        }
        ans = min(ans,dp[i+1]+1);
        dp[i] = ans;
        //pr(i) pr(ans) nl 
    }
    printa(dp,n+1)
    
    cout<<dp[1]<<endl;
    return 0;
}
