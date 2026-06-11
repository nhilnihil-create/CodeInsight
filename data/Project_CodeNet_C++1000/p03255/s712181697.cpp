#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define sz(v) (int)(v).size()
#define pb push_back
#define sc second
#define fr first
#define sor(v) sort(v.begin(),v.end())
#define rev(s) reverse(s.begin(),s.end())
#define lb(vec,a) lower_bound(a)
#define ub(vec,a) upper_bound(a)
#define uniq(vec) vec.erase(unique(vec.begin(),vec.end()),vec.end())
using namespace std;
typedef long long int ll;
typedef pair <int, int> P;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll N;
    ll X;
    cin>>N>>X;
    ll x[N];
    rep(i,0,N) cin>>x[i];
    ll ans=1e17;
    ll s[N+1];
    s[0]=0;
    rep(i,1,N+1) s[i]=s[i-1]+x[i-1];
    rep(i,1,N+1){
        ll res=X*(N+i);
        res+=5*(s[N]-s[N-i]);
        rep(k,1,N/i){
            res+=(3+2*k)*(s[N-k*i]-s[N-(k+1)*i]);
            if(res>ans){
                res=ans;
                break;
            }
        }
        if(N%i) res+=(N/i*2+3)*s[N%i];
        ans=min(ans,res);
    }
    cout<<ans<<"\n";
}