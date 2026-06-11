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
int N;
P A[1<<18];
ll dp[1<<18];
P getmax(P x, P y){
    ll a[4];
    a[0]=x.fr; a[1]=x.sc; a[2]=y.fr; a[3]=y.sc;
    sort(a,a+4);
    return P(a[3], a[2]);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N;
    rep(i,0,1<<N){
        ll a;
        cin>>a;
        A[i]=P(a,0);
    }
    rep(i,0,N){
        rep(j,0,1<<N){
            if (j&(1<<i)){
                A[j]=getmax(A[j], A[j^(1<<i)]);
            }
        }
    }
    dp[1]=A[1].fr+A[1].sc;
    cout <<dp[1]<<"\n";
    rep(i,2,1<<N){
        dp[i]=max(dp[i-1], A[i].fr+A[i].sc);
        cout <<dp[i]<<"\n";
    }
}