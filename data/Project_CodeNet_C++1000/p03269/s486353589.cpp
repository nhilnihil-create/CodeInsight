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
    int l,m=-1;cin>>l;
    vi v;
    while(l!=0){
        if((l&1)==1){
            v.pb(1);
            m++;
        }
        else v.pb(0);
        l>>=1;
    }
    int n=v.size();
    m+=(n-1)*2;
    cout<<n<<' '<<m<<endl;
    int sum=1;
    rep(i,n-1){
        int j=n-i-2;
        cout<<i+1<<' '<<i+2<<' '<<0<<endl;
        cout<<i+1<<' '<<i+2<<' '<<sum<<endl;
        sum*=2;
        if(v[j]==1){
            cout<<1<<' '<<i+2<<' '<<sum<<endl;
            sum++;
        }
    }
}