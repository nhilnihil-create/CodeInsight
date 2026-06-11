//Jai Bhole Ki
#include <bits/stdc++.h>
using namespace std;
#define fast static int fastline = []() { std::ios::sync_with_stdio(false); cin.tie(NULL); return 0; }();
#define ll long long
#define LL unsigned ll
#define pb push_back
#define pi pair<ll,ll>
#define debug(x) cout<<x<<"\n";
#define debugg cout<<"debugged\n";
#define setpr(xval) cout<<fixed<<setprecision(12)<<xval<<endl;
#define minval -2e9
#define maxval 2e9
long double PI =3.14159265358979323846;
 
const ll M=1e9+7;
const ll inf=1e18;
const ll ms=2e5+5;
fast;
ll n,ans;
bool compare(pi &a,pi &b)
{
    return a.first>b.first;
}
void solve()
{
   cin>>n;map<ll,ll>mpe,mpo;
   for(int i=0;i<n;i++)
   {
       ll a;cin>>a;
       if(i%2==0)
        mpo[a]++;
        else
        mpe[a]++;
   }
   vector<pi> ar(n/2+2,{0,0}),are(n/2+2,{0,0});
   ll i=0;
   for(auto it:mpo)
   {
       ar[i].first=it.second;ar[i].second=it.first;i++;
   }i=0;
   for(auto it:mpe)
   {
       are[i].first=it.second;are[i].second=it.first;i++;
   }
   sort(ar.begin(),ar.end(),compare);sort(are.begin(),are.end(),compare);
   if(ar[0].second==are[0].second)
   {
        ll temp=n-max(ar[0].first+are[1].first,ar[1].first+are[0].first);
        cout<<temp<<endl;
   }
   else
   {
       ll temp=n-ar[0].first-are[0].first;
        cout<<temp<<endl;
   }
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