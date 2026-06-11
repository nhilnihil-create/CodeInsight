//      https://youtu.be/X_hMZYDMps4

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef long long unsigned llu;
typedef pair<long long, long long> pll;
const long long inf = 2000000000000000000LL;    // 2e18
#define pi                  acos(-1.0)
#define fast                ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define nl                  "\n"
#define ff                  first
#define ss                  second
#define pb                  push_back
#define pf                  push_front
#define all(x)              x.begin(),x.end()
#define debug(x)            cout<<"debug "<<x<<"\n"

int main()
{
    fast;
    ll t,i,j,k,l,m,n,o,p,q,temp,ans=0,flag=0,mod=1000000007,odd=0,even=0,a,b;
    string s;
    cin>>s;
    for(i=0,temp=0;i<s.size();i++){
        if(s[i]=='B') temp++;
        if(s[i]=='W') ans+=temp;
    }
    cout<<ans;
}
