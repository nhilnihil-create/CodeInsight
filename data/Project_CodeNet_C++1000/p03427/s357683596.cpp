#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define endl "\n"
#define pb push_back
#define f(i,n) for(i=0;i<n;i++)
#define F(i,a,b) for(i=a;a<=b;i++)
#define arr(a,n) for( i=0;i<n;i++)cin>>a[i];
#define fi first
#define se second
#define mp make_pair
#define mod 1000000007
#define YES cout<<"YES"<<endl;
#define Yes cout<<"Yes"<<endl;
#define NO cout<<"NO"<<endl;
#define No cout<<"No"<<endl;
#define yes cout<<"yes"<<endl;
#define no cout<<"no"<<endl;
#define vi vector<ll>
#define ed end()
#define bg begin()
#define sz size()
#define ln length()
#define s() sort(a,a+n);
#define sr() sort(a,a+n,greater<ll>());
#define v()  sort(v.begin(),v.end());
#define vr() sort(v.begin(),v.end(),greater<ll>());
#define mod 1000000007
#define fast() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
ll gcd(ll a, ll b){if(!b)return a;return gcd(b, a % b);}
ll power(ll x,ll y,ll p){ll res=1;x%=p;while(y>0){if(y&1)res=(res*x)%p;y=y>>1;x=(x*x)%p;}return res;}
int main() {
    /*#ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif*/
        

fast();
//ll t;cin>>t;while(t--)
{
  ll n,ans=0;
  cin>>n;
  string s=to_string(n);
  if(s[0]!='9')
   {
    ll temp=(0+s[0]-'0');
  
    cerr<<temp<<endl;
    ans+=(temp-1);
   
  for(int i=1;i<s.length();i++)
  {
    ans+=9;
  }
  ll aise=0;
  while(n>0)
  {
      aise+=(n%10);
      n/=10;
  }
  cout<<max(ans,aise)<<endl;
}
else
{ 
  ll idx=-1;
  for(int i=0;i<s.length();i++)
  {
    if(s[i]=='9')
      continue;
    else
    {
      idx=i;
      break;
    }
  }
  if(idx==-1)
  {
    for(int i=0;i<s.length();i++)
    {
      ans+=9;
    }
  }
  else
  {
    for(int i=0;i<idx-1;i++)
    {
      ans+=9;
    }
    ans+=8;
    for(int i=idx;i<s.length();i++)
    {
      ans+=9;
    }
  }

cout<<ans<<endl;
}
}
return 0;
}