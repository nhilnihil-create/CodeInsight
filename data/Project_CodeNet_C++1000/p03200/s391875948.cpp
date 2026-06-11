#include<bits/stdc++.h>
#define FRU freopen("out.txt","w",stdout)
#define FRO freopen("in.txt","r",stdin)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mem(ara,n) memset(ara,n,sizeof ara)
#define loop(i,j,n) for(i=j;i<n;i++)
#define rloop(i,j,n) for(i=n;i>=j;i--)
#define INF 2147483647
#define ll long long
#define pii pair<int,int>
#define eps 1e-9
#define mii map<int,int>
#define vi vector<int>
#define all(n) n.begin(),n.end()
#define inf INF
#define INFLL 9223372036854775807
using namespace std;
string s;
int main()
{
    int n,m,cnt=0,i,j,k,tc,t;

    cin>>s;
    n=s.length();
    ll ans=0;
    cnt=0;
    for(i=0;i<n;i++)
    {
        if(s[i]=='W')ans+=(ll)(i-cnt ),cnt++;
    }
    cout<<ans<<endl;

}
