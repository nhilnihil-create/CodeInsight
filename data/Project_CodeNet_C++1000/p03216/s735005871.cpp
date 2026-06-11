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
typedef pair <int, int> P;

const ll MOD=1000000007;
ll N,Q;
string S;
ll k[75];
ll s[1000001], ss[1000002], c[1000001], m[1000002];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>S>>Q;
    rep(i,0,Q){
        cin>>k[i];
    }
    rep(i,0,N){
        s[i+1]=s[i]+(S[i]=='M'?1:0);
        ss[i+2]=ss[i+1]+s[i+1];
        c[i+1]=c[i]+(S[i]=='C'?1:0);
        m[i+2]=m[i+1]+(S[i]=='C'?s[i]:0);
    }
    rep(x,0,Q){
        ll K=k[x];
        ll ans=0;
        rep(i,0,N){
            if(S[i]=='D'){
                ans+=(i+K<=N?m[i+K+1]:m[N+1])-m[i+1];
                ans-=((i+K<=N?c[i+K]:c[N])-c[i])*s[i];
            }
        }
        cout <<ans<<"\n";
    }
}