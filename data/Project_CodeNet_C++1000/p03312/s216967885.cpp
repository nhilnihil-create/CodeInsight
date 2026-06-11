#include <bits/stdc++.h>
using namespace std;
#define rep(i, n)  for(long long i=0;i<(long long)(n);i++)
#define REP(i,k,n) for(long long i=k;i<(long long)(n);i++)
#define all(a) a.begin(),a.end()
#define eb emplace_back
#define pb push_back
#define lb(v,k) (lower_bound(all(v),k)-v.begin())
#define chmin(x,y) if(x>y)x=y
#define chmax(x,y) if(x<y)x=y
typedef long long ll;
typedef pair<ll,ll> P;
typedef tuple<ll,ll,ll> PP;
typedef priority_queue<ll> PQ;
typedef priority_queue<ll,vector<ll>,greater<ll>> SPQ;
using vi=vector<ll>;
using vvi=vector<vector<ll>>;
using vc=vector<char>;
using vvc=vector<vector<char>>;
const ll inf=1001001001001001;
const int Inf=1001001001;
const int mod=1000000007;
int main(){
    ll n,ans=inf;cin>>n;
    vi v(n);
    cin>>v[0];
    REP(i,1,n){
        int a;cin>>a;
        v[i]=v[i-1]+a;
    }
    ll l=-1,r=0,m=inf,p=inf;
    REP(k,1,n+1){
        while((l+1<k)&&((abs(v[k-1]-v[l+1]-v[l+1]))<abs(m))){
          m=v[k-1]-v[l+1]*2;
            l++;
        }
        while(r<n&&abs(v[n-1]-v[r]*2+v[k-1])<abs(p)){
            p=v[n-1]-v[r]*2+v[k-1];
            r++;
        }
        ll a=v[n-1]-v[r-1],b=v[r-1]-v[k-1],c=v[k-1]-v[l],d=v[l];
        chmin(ans,max(max(a,b),max(c,d))-min(min(a,b),min(c,d)));
        m+=(v[k]-v[k-1]);
        if(k==r)r++;
        else p+=(v[k]-v[k-1]);
    }
    cout<<ans<<endl;
}