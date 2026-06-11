#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
#define all(q) (q).begin(),(q).end()
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int arr[5000],n;
int dp[3000][2][2];
int recur(int pos,int x,int y,int t,int last)
{
    if(pos==n)
    {
        return abs(x-y);
    }
    int &ret=dp[pos][t][last];
    if(~ret)
        return dp[pos][t][last];
    ret=0;
    if(pos+1<n)
        ret=recur(pos+1,x,y,t,last);
    if(t)
    {
        t^=1;
      //  ret=max(ret,recur(pos+1,x,y,t,0));
        ret=max(ret,recur(pos+1,x,arr[pos],t,1));
    }
    else
    {
        t^=1;
       // ret=max(ret,recur(pos+1,x,y,t,0));
        ret=max(ret,recur(pos+1,arr[pos],y,t,1));
    }
    return ret;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    memset(dp,-1,sizeof(dp));
    int x,y,pos=0,t=0;
    cin>>n>>x>>y;
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cout<<recur(0,x,y,0,0)<<endl;

    return 0;
}
