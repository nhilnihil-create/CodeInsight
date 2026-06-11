#include <bits/stdc++.h>
#include <fstream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


typedef  long long ll;
typedef long double ld;
using namespace std;
using namespace __gnu_pbds;


#define endl "\n"
#define FIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
const int N=2e5+5;
ll mod=1e9+7;

ll mul (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a*b)%mod;
}
ll add (ll a, ll b)
{
    a%=mod;
    b%=mod;
    return (a+b+mod)%mod;
}
ll fastpow(ll b, ll p)
{
    if(p==0)
        return 1;
    ll ans=fastpow(b,p/2);
    ans=mul(ans,ans);
    if(p%2)ans=mul(ans,b);
    return ans;
}
pair<int,int>arr[N];
int main()
{
    FIO
    priority_queue<int,vector<int>,greater<int>> q;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        q.push(x);
    }
    for(int i=0;i<m;i++)
        cin>>arr[i].second>>arr[i].first;
    sort(arr,arr+m);
   for(int i=m-1;i>=0;i--)
   {
       if(q.top()>=arr[i].first)
        break;
       while(q.top()<arr[i].first&&arr[i].second>0)
       {
           q.pop();
           q.push(arr[i].first);
           arr[i].second--;
       }
   }
   ll ans=0;
   while(q.size())
    ans+=q.top(),q.pop();
   cout<<ans;






    return 0;
}