#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 41
#define INF 100000000
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 100005;
const int MOD = 1000000007;
int main(){
    int n;
    ll k;
    cin>>n>>k;
    vector<ll>a(n);
    REP(i,n)IN(a[i]);
    ll x=0;
    vector<int>t(N,0);
    REP(i,N){
        REP(j,n){
            if(a[j]&(ll)(1LL<<i))t[i]++;
        }
    }
    for(int i=N-1;i>=0;i--){
        if(t[i]<=n/2&&(ll)((1LL<<i)|x)<=k){
            x|=(ll)(1LL<<i);
        }
        //cout<<t[i]<<" "<<x<<endl;
    }
    ll ans=0;
    REP(i,n){
        ans+=(ll)(x^a[i]);
    }
    OUT(ans);
    return 0;
}