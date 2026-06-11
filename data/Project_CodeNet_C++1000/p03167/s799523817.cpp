#include<bits/stdc++.h>
#define ll long long
#define Test int t;cin>>t;while(t--)
#define PI acos(-1)
#define endl "\n"
#define fx(x) fixed<<setprecision(x)
#define sz(s) (int)s.size()
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define mem(a,n) memset((a),n,sizeof (a))
const double eps=1e-9;
const int mod=1e9+7;
int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};
ll gcd(ll x,ll y) {return(!y)?x:gcd(y,x%y);}
ll lcm(ll x,ll y) {return((x/gcd(x,y))*y);}
using namespace std;
void fast(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int dp[1001][1001];
int n,m;
char a[1001][1001];
bool valid(int i,int j){
    return (i>=0&&i<n&&j>=0&&j<m&&a[i][j]!='#');
}
int solve(int i,int j){
    if(i==n-1&&j==m-1)return 1;
    int &ret=dp[i][j];
    if(~ret)return ret;
    ret=0;
    if(valid(i+1,j))ret+=solve(i+1,j)%mod;
    if(valid(i,j+1))ret+=solve(i,j+1)%mod;
    return ret%mod;
}
int main()
{
    mem(dp,-1);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    cout<<solve(0,0);
    return 0;
}
