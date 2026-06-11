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
double dis(double x,double y)
{
    if(x<=0 && y>=0)
    {
        return abs(x)+y;
    }
    if(x>=0 && y<=0)
    {
        return abs(x)+abs(y);
    }
    return abs(abs(x)-abs(y));
}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    double t,mn=INT_MAX,ans,x,y;
    int n;
    cin>>n;
    cin>>x>>y;
    for(int i=1; i<=n; i++)
    {
        double a,cur;
        cin>>a;
        cur=x-(a*0.006);
        cur=dis(y,cur);
        if(cur<mn){
            mn=cur;
            ans=i;
        }
    }
    cout<<ans<<endl;


    return 0;
}
