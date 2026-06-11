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
ll arr[MAX],pre_dist[MAX],suf_dist[MAX];
ll find_distance(int x,int y)
{
    if(x>=0 && y>=0)
    {
        if(y>=x)
            return y-x;
        else
            return x-y;
    }
    else if(x<=0 && y<=0)
    {
        x=abs(x);
        y=abs(y);
        if(y>=x)
            return y-x;
        else
            return x-y;

    }
    else if((x>=0 && y<=0) || (x<=0 && y>=0))
        return abs(x)+abs(y);

}
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n;
    cin>>n;
    for(int i=1; i<=n; i++)
        cin>>arr[i];
    for(int i=1; i<=n; i++)
    {
        pre_dist[i]=pre_dist[i-1]+find_distance(arr[i-1],arr[i]);
    }
    for(int i=n; i>=1; i--)
    {
        suf_dist[i]=suf_dist[i+1]+find_distance(arr[i+1],arr[i]);
    }
    for(int i=1; i<=n; i++)
    {
        ll x=pre_dist[i-1];
        ll y=suf_dist[i+1];

        ll connect;
        if(i==n)
        {
            connect=find_distance(arr[n-1],0);
        }
        else
        {
            connect=find_distance(arr[i-1],arr[i+1]);
        }
        //  cout<<i<<" "<<x<<" "<<y<<" "<<connect<<endl;
        cout<<connect+x+y<<endl;
    }

    return 0;
}
