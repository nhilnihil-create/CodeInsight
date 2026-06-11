#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define ff first
#define mp make_pair
#define ss second
#define rep(i,a,b) for(int i = a; i < b; i++)
#define repp(i,a,b) for(int i = a; i <= b; i++)
#define endl '\n'
#define mod 1000000007
#define mod_in(a) bin(a, mod - 2)
#define fact(n) rep(i, 1, n+1) ft.pb((ft[i-1] * i) % mod)
#define ncr(n, r) (n >= r ? ((ft[n] * mod_in((ft[r] * ft[(n)-(r)]) % mod)) % mod) : 0LL)
#define pi 3.14159265358979323
#define INF 1e15
#define lb(v, a) lower_bound(v.begin(), v.end(), a)
#define ub(v, a) upper_bound(v.begin(), v.end(), a)

int power(int x, int n){
    int res=1;
    while(n>0){
        if(n&1)
            res=res*x;
        x*=x;
        n>>=1;
    }
    return res;
}

int bin(int x, int n){
    int res=1; x%=mod;
    while(n){
        if(n&1) res=(res*x)%mod;
        x=(x*x)%mod;
        n>>=1;
    }
    return res;
}

bool prime(int n){
    if(n==3)return 1;
    repp(i,2,sqrt(n)){
        if(n%i==0)return 0;
    }
    return 1;
}


// vector<int> adj[2000005];
// vector<int> pr(2000005, 1), xx[2000005];
// void sieve(int n){ 
//     for(int p=2; p<n; p++){ 
//         if(pr[p]){ 
//             for(int i=p; i<n; i += p){
//                 pr[i]=0;
//                 xx[i].pb(p);
//             }
//         } 
//     } 
// }  
// vector<int> ft(40);

void solve(){
    string s, t; cin>>s>>t;
    if(s.size() > t.size()) swap(s, t);
    int dp[s.size()][t.size()];
    rep(i,0,s.size()){
        rep(j,0,t.size()){
            dp[i][j]=0;
        }
    }
    rep(i,0,s.size()){
        rep(j,0,t.size()){
            if(s[i]==t[j] && i && j){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else if(s[i]==t[j]) dp[i][j] = 1;
            else{
                if(i) dp[i][j] = dp[i-1][j];
                if(j) dp[i][j] = max(dp[i][j], dp[i][j-1]);
            }
        }
    }
    int i=s.size()-1, j=t.size()-1;
    stack<char> res;
    while(i >=0 && j>=0){
        if(s[i]==t[j]){
            res.push(s[i]);
            i--; j--;
        }
        else{
            if( i && j){
                if(dp[i-1][j] > dp[i][j-1]){
                    i--;
                }
                else j--;
            }
            else if(i) i--;
            else j--;
        }
    }
    while(!res.empty()){
        cout<<res.top();
        res.pop();
    }
}

signed main(){
    fast
    int t=1;
    // cin>>t;
    while(t--) solve();
}