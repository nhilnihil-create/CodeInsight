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
int a[]={2,5,63,20,30};
ll gcd(ll x,ll y)
{
	if(x==0) return y;
	return gcd(y%x,x);
}
signed main(){
    cin.tie(0);
	ios::sync_with_stdio(false);
    cin>>N;
    if(N<=5){
        rep(i,0,N){
            cout<<a[i];
            if(i!=N-1)cout<<" ";
        }
        return 0;
    }
   vint ans;
   rep(i,0,30000/4+1){
       ans.pb(i*6+2);
       ans.pb(i*6+3);
       ans.pb(i*6+4);
       ans.pb((i+1)*6);
   }
   if(N%8==7||N%8==0){
       rep(i,0,N){
           cout<<ans[i];
           if(i!=N-1)cout<<" ";
       }
   }else if(N%8==1||N%8==6){
        rep(i,0,N){
            if(ans[i]==8)continue;
            cout<<ans[i]<<" ";
        }
        cout<<30000;
    }else if(N%8==3||N%8==4){
        rep(i,0,N){
            if(ans[i]==9)continue;
            cout<<ans[i]<<" ";
        }
        cout<<30000;
    }else {
        rep(i,0,N){
            if(ans[i]==9)continue;
            cout<<ans[i]<<" ";
        }
        cout<<29998;
    }
    cout<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}