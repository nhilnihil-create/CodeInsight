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
int N,K,Q;
vector<ll> A;
vector<ll> B;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>N>>K>>Q;
    A.resize(N);
    B.resize(N);
    rep(i,0,N){
        cin>>A[i];
        B[i]=A[i];
    }
    sor(B);
    uniq(B);
    map<ll,ll> m;
    map<ll,ll> revm;
    rep(i,0,sz(B)){
        m[B[i]]=i;
        revm[i]=B[i];
    }
    rep(i,0,N){
        A[i]=m[A[i]];
    }
    ll ans=1e12;
    int n=sz(B);
    rep(i,0,n){
        int ng=i-1, ok=n;
        while(ok-ng>1){
            int mid=(ok+ng)/2;
            int l=0, r=0;
            int cnt=0;
            int res=0;
            while(l<N){
                cnt=0;
                while(r<N&&A[r]<i){
                    r++;
                }
                l=r;
                while(r<N&&A[r]>=i){
                    if(A[r]<=mid) cnt++;
                    r++;
                }
                res+=max(0,min(r-l-K+1,cnt));
                l=r;
            }
            if(res>=Q) ok=mid;
            else ng=mid;
        }
        if(ok==n) continue;
        else ans=min(ans,revm[ok]-revm[i]);
    }
    cout <<ans<<"\n";
}