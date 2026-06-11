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
    ll k,a,b,c=1,kk;
    cin>>k>>a>>b;
    kk=k;
    if(c<a)
    {
      k-=(a-c);
      c=a;
     
    }
    //cerr<<k<<endl;
    
      if(a<b-1&&k>1)
      {   
          ll temp=k/2;
          //cerr<<"Temp = "<<temp<<endl;
          c=c-((1ll*temp)*a);
          //cerr<<"CC = "<<c<<endl;
          c=c+(1ll*temp*b);
          //cerr<<"C "<<c<<endl;
          //c=c-((1ll*temp)*a);
         // cerr<<c<<endl;
          k=k-(temp*2);
          if(k>0)
          {
            c+=k;
          }

      }
      cout<<max(kk+1,c)<<endl;
      
    }

return 0;
}