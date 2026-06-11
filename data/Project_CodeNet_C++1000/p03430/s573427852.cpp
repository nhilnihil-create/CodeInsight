#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
typedef long long ll;
typedef double D;
const ll inf=(1ll<<61);
const ll mod=1e9+7;
const int MX=302;
int n,k,dp[MX][MX][MX];
string s,t;
int DP(int x,int y,int k){
    if(k<0)return -MX*2;
    if(x>y)return 0;
    if(x==y)return 1;
    int &ret=dp[x][y][k];if(ret!=-1)return ret;
    ret=DP(x+1,y,k);
    ret=max(ret,DP(x,y-1,k));
    if(s[x]==s[y]){
        ret=max(ret,DP(x+1,y-1,k)+2);
    }
    ret=max(ret,DP(x+1,y-1,k-1)+2);
    return ret;
}
int main(){
    cin>>s>>k;n=s.size();
    memset(dp,-1,sizeof(dp));
    cout<<DP(0,n-1,k)<<endl;
}
