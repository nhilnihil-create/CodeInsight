//Jai Bhole Ki
#include <bits/stdc++.h>
using namespace std;
#define fast static int fastline = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
#define ll long long
#define LL unsigned ll
#define pb push_back
#define pi pair<ll,ll>
#define debug(x) cout<<x<<"\n";
#define debug cout<<"debugged\n";
#define minval -2e9
#define maxval 2e9
long double PI =3.14159265358979323846;
 
const ll M=1e9+7;
const ll inf=1e18;
const ll ms=2e5+5;
fast;
ll ans,k,n,sum,temp;
void solve()
{
    cin>>n>>k;vector<ll>ar(n),arr(n-1);
    for(int i=0;i<n;i++)
    {
        cin>>ar[i];
    }
    sort(ar.begin(),ar.end());
    for(int i=0;i<n-1;i++)
        arr[i]=ar[i+1]-ar[i];
    k--;
    for(int i=0;i<k;i++)
    {
        temp+=arr[i];
    }
    ans=temp;
    for(int i=k;i<n-1;i++)
    {
        temp+=arr[i];temp-=arr[i-k];
        //cout<<temp<<endl;
        ans=min(temp,ans);
    }
    cout<<ans<<endl;
}
int main()
{
 // freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    //int t;cin>>t;while(t--)
    {
        solve();
    }
    return 0;
}