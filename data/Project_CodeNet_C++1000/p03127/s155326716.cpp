#include<bits/stdc++.h>
#include<string.h>
#define pb push_back
#define all(v) v.begin(),v.end()
#define see(x) cout<<#x<<" : "<<(x)<<endl;
#define ya cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;
#define ff first
#define sc second
typedef long long ll;
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL),cout.tie(NULL);
    //freopen("test.txt","r",stdin);
    ll n,ind=0,i,j,ans=0,ev=0,od=0;
    cin>>n;
    vector<ll>v(n);
    bool ok=1;
    for(i=0;i<n;i++)
    {
        cin>>v[i];
        ans=__gcd(v[i],ans);
    }
    cout<<ans<<endl;

    return 0;
}

