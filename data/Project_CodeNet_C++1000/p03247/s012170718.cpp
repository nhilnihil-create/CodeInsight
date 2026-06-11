#include <bits/stdc++.h>

#define int long long

using namespace std;
#define rep(i,s,n) for(int i = s;i<n;i++)
#define repe(i,s,n) for(int i = s;i<=n;i++)
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007,INF=1e18;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

int n,x[1111],y[1111],s[1111];

signed main(){
    cin>>n;
    rep(i,0,n){
        cin>>x[i]>>y[i];
        s[i]=x[i]+y[i];
        if((s[i]-s[0])%2!=0){
            puts("-1");
            return 0;
        }
    }
    vint values;
    for(int i=30;i>=0;i--)values.pb(1<<i);
    if(s[0]%2==0)values.pb(1);
    int m=values.size();
    cout<<m<<endl;
    rep(i,0,m){
        if(i==m-1)cout<<values[i]<<endl;
        else cout<<values[i]<<" ";
    }
    
    rep(i,0,n){
        int u=x[i]+y[i];
        int v=x[i]-y[i];
        for(auto&& e : values){
            if(u>=0){
                if(v>=0){
                    cout<<"R";
                    u-=e;
                    v-=e;
                }else{
                    cout<<"U";
                    u-=e;
                    v+=e;
                }
            }else{
                if(v>=0){
                    cout<<"D";
                    u+=e;
                    v-=e;
                }else{
                    cout<<"L";
                    u+=e;
                    v+=e;
                }
            }
        }
        cout<<endl;
    }
    
    
    
    
    
    
    
    
    
    
    return 0;
}