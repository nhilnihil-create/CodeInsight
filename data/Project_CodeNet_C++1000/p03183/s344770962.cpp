#include <bits/stdc++.h>
#define rep(i, a, b) for(ll i = ll(a); i < ll(b); i++)
#define rer(i, a, b) for(ll i = ll(a) - 1; i >= ll(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(vec.begin(),vec.end(),a)
#define ub(vec,a) upper_bound(vec.begin(),vec.end(),a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <ll, ll> P;

const ll MOD=1000000007;
ll dp[1010][20010];
ll W[1000], S[1000], V[1000];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin>>N;
    ll w[N], s[N], v[N];
    P p[N];
    rep(i,0,N){
        cin>>w[i]>>s[i]>>v[i];
        p[i]=P(s[i]+w[i],i);
    }
    sort(p,p+N);
    rep(i,0,N){
        W[i]=w[p[i].sc];
        S[i]=s[p[i].sc];
        V[i]=v[p[i].sc];
    }
    if(N==1){
        cout <<V[0]<<"\n";
        return 0;
    }
    rep(i,0,N){
        rep(j,0,20001){
            if(i==0){
                if(j>=W[i]) dp[i][j]=V[i];
                else dp[i][j]=0;
            }
            else{
                if(j==0) dp[i][j]=0;
                else{
                    dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                    if(j-W[i]>=0&&j-W[i]<=S[i]){
                        dp[i][j]=max(dp[i][j],dp[i-1][j-W[i]]+V[i]);
                    }
                }
            }
        }
    }
    cout <<dp[N-1][20000]<<"\n";
}