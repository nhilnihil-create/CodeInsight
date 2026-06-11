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
 
const ll M=1e7+7;
const ll inf=1e18;
const ll ms=2e5+5;
fast;
void solve()
{
    string n;ll m;
    cin>>n>>m;
    int i=0;
    while(i<n.size()&&n[i]=='1')
        i++;
    if(i<n.size()&&m>i)
        cout<<n[i];
    else
        cout<<1;
}
int main()
{
 // freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    //int t;cin>>t;for(int te=1;te<=t;te++)
    {
        solve();
    }
    return 0;
}