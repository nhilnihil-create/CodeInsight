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
int arr[MAX];
int main()
{
    FastRead
    //freopen("output.txt", "w", stdout);
    int n,mx=-INT_MAX,x=0,mn=INT_MAX,y=0;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>arr[i];
        if(mx<arr[i])
        {
            mx=arr[i];
            x=i;
        }
        if(mn>arr[i])
        {
            mn=arr[i];
            y=i;
        }
    }
    vector<pair<int,int> >v;
    if(mx>=0 && mn<=0)
    {
        if(abs(mx)>=abs(mn))
        {
            for(int i=1; i<=n; i++)
            {
                arr[i]+=mx;
                v.push_back({x,i});
            }
        }
        else
        {
            for(int i=1; i<=n; i++)
            {
                arr[i]+=mn;
                v.push_back({y,i});
            }
        }
    }
    int f=0;
    if(arr[1]>=0)
    {
        for(int i=2; i<=n; i++)
        {
            arr[i]+=arr[i-1];
            v.push_back({i-1,i});
        }
    }
    else
    {
        for(int i=n-1; i>=1; i--)
        {
            arr[i]+=arr[i+1];
            v.push_back({i+1,i});
        }
    }

    cout<<v.size()<<endl;
    for(auto i:v)
        cout<<i.first<<" "<<i.second<<endl;

    return 0;
}
