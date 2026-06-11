#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<deque>
#include<map>
#include<queue>
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
const int mod=1000000007;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

long long h1[120000],h2[120000],h3[120000],h4[120000],x[120000],y[120000];
long long m,s,t;

//#define int ll
signed main(){
    ll n,c;
    cin>>n>>c;
    repe(i,1,n)cin>>x[i]>>y[i];
    
    t=0;
    for(int i=1;i<=n;i++){
        t=t+y[i];
        h1[i]=max(h1[i-1],t-x[i]);
        h2[i]=max(h2[i-1],t-2*x[i]);
    }
    
    t=0;
    for(int i=n;i>0;i--){
        t=t+y[i];
        h3[i]=max(h3[i+1],t-(c-x[i]));
        h4[i]=max(h4[i+1],t-2*(c-x[i]));
    }
    
    rep(i,0,n+1){
        s=max(s,max(h1[i]+h4[i+1],h2[i]+h3[i+1]));
    }
    
    cout<<s<<endl;
    return 0;
}