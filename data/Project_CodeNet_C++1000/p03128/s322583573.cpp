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
string dp[10005];
int cost[200],n,m,arr[500];
string cmp(string x,string y)
{
    if(x.length()<y.length())
        return y;
    if(x.length()>y.length())
        return x;
    return max(x,y);
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    cost[1]=2;
    cost[2]=5;
    cost[3]=5;
    cost[4]=4;
    cost[5]=5;
    cost[6]=6;
    cost[7]=3;
    cost[8]=7;
    cost[9]=6;
    string X="-";
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        cin>>arr[i];
    }
    for(int i=0; i<=n; i++)
        dp[i]=X;
    dp[0]="";
    for(int i=0; i<=n; i++)
    {
        if(dp[i]==X)
            continue;
        for(int j=0; j<m; j++)
        {
            string z="0";
            z[0]+=arr[j];
            dp[i+cost[arr[j]]]=cmp(dp[i+cost[arr[j]]],dp[i]+z);
        }
    }
    cout<<dp[n]<<endl;





    return 0;
}
