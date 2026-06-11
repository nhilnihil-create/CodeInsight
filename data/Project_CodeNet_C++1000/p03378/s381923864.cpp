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
int cost[500];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,m,p;
    cin>>n>>m>>p;
    for(int i=0; i<m; i++)
    {
        int a;
        cin>>a;
        cost[a]=1;
    }
    int x=0,y=0;
    for(int i=p;i>0;i--)
    {
        x+=cost[i];
    }
    for(int i=p;i<n;i++)
    {
        y+=cost[i];
    }
    cout<<min(x,y)<<endl;
    return 0;
}
