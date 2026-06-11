#include <bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define rrep(i,s,n) for(int i = (n)-1;i>=(s);i--)
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define fi first
#define se second
#define chmin(a,b) a=min((a),(b))
#define chmax(a,b) a=max((a),(b))
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
typedef pair<pint,int> P1;
typedef pair<int,pint> P2;
typedef pair<pint,pint>PP;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007;
const ll INF=1e18;
int dx[]={0,0,1,-1};
int dy[]={-1,1,0,0};

int N;

signed main(){
    cin.tie(0);
	ios::sync_with_stdio(false);
    cin>>N;
    int k=2;
    while(k*(k-1)<N*2){
        k++;
    }
    if(k*(k-1)!=N*2){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;
    cout<<k<<endl;
    vector<vint> G(k);
    
    int pos=1;
    rep(i,0,k){
        rep(j,1,k-i){
            G[i].pb(pos);
            G[i+j].pb(pos);
            pos++;
        }
    }
    
    rep(i,0,k){
        cout<<k-1;
        for(auto x:G[i])cout<<" "<<x;
        cout<<endl;
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}