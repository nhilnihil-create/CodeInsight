/* Author : Aaryan Srivastava ^__^ */ 
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back   
#define sz(a) ((int)a.size())
using namespace std;
typedef long long ll ; 
const ll inf = 1e18 ;
const int mod = 1e9 + 7;
const int N = 3e5 + 5; 
const int SZ = 101;
ll po(ll x,ll y,ll p = mod) {ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
typedef pair<int , int> pii;

int a[(1 << 18) + 5];


void get_better(pair<pii, pii>& p , pair<pii , pii> add){
    if(p.ff > add.ff){
        if(p.ss < add.ff)
            p.ss = add.ff;
    }else if(p.ff < add.ff){
        if(p.ff < add.ss){
            p = add;
        }else{
            p.ss = p.ff ;
            p.ff = add.ff;
        }
    }else{
        if(p.ss < add.ss){
            p.ss = add.ss; 
        }
    }
}

void solve(){
    int n ;
    cin >> n ;
    for(int i = 0 ; i < (1 << n) ; ++i) cin >> a[i];
    pair<pii , pii> dp[1 << n] = {} ;
    for(int i = 0 ; i < (1 << n) ; ++i){
        get_better(dp[i] , {{a[i] , i} , {-1 , -1}});
        for(int b = 0 ; b < n ; ++b){
            if(i >> b & 1) continue ;
            get_better(dp[i | (1 << b)] , dp[i]);
        }
    }
    int ans = 0 ;
    for(int i = 0; i < (1 << n) ; ++i){
        // print(dp[i]);
        ans = max(ans , dp[i].ff.ff + dp[i].ss.ff);
        if(i) cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);
    int TC = 1, t = 0;
    // cin >> TC ;
    while(t++ < TC)
    {
        // cout << "Case #" << t << ": " ;
        solve();
        cout << "\n" ;
    }
    return 0;
}