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
typedef pair<pint,int> P1;
typedef pair<int,pint> P2;
static const ll maxLL = (ll)1 << 62;
const ll MOD=1000000007,INF=1e18;
int dy[]={-1,0,1,0};
int dx[]={0,1,0,-1};

int n,x,y,cnt,flag;
bool dp[8009][32009];
vint v1,v2,v3;
string s;

bool solve(vint vec,int g){
    rep(i,0,vec.size()+1)rep(j,0,32000+1)dp[i][j]=false;
    dp[0][16000]=true;
    rep(i,0,vec.size()){
        rep(j,0,32000+1){
            if(!dp[i][j])continue;
            dp[i+1][j+vec[i]]=true;
            dp[i+1][j-vec[i]]=true;
        }
    }
    return dp[vec.size()][16000+g];
}

signed main(){
    cin>>s>>x>>y;
    rep(i,0,s.size()+1){
        if(i!=s.size()&&s[i]=='F')cnt++;
        else{
            if(flag==0)v1.pb(cnt);
            if(flag==1)v2.pb(cnt);
            cnt=0;
            flag?flag=0:flag=1;
        }
    }
    x-=v1[0];
    rep(i,1,v1.size())v3.pb(v1[i]);
    if(solve(v3,x)&&solve(v2,y))cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    
    
    
    
    
    return 0;
}