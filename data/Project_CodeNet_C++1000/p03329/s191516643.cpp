#include<bits/stdc++.h>
using namespace std;
///Welcome to Nasif's Code
#define bug printf("bug\n");
#define bug2(var) cout<<#var<<" "<<var<<endl;
#define co(q) cout<<q<<endl;
typedef long long int ll;
typedef unsigned long long int ull;
const int MOD = (int)1e9+7;
const int MAX = 1e6;
#define pi acos(-1)
#define inf 1000000000000000LL
#define FastRead    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int dp[100005][4];
int recur(int n,int last)
{
    if(n<6)
        return n;
    int &ret=dp[n][last];
    if(ret)
        return ret;
    ret=INT_MAX;
    for(int i=6; i<=n; i*=6)
        ret=min(ret,recur(n-i,1)+1);
    for(int i=9; i<=n; i*=9)
        ret=min(ret,recur(n-i,2)+1);
    return ret;
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    cout<<recur(n,0)<<endl;
    return 0;
}
