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
bool sortbysec(const pair<ll,ll> &a, 
              const pair<ll,ll> &b) 
{ 
    return (abs(a.first-a.second) >abs(b.first- b.second)); 
} 
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
    ll n,atotal=0,btotal=0,f=1;
    cin>>n;
    ll a[n],b[n];
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      atotal+=a[i];
    }
    vector<pair<ll,ll> >v,vv;
    for(int i=0;i<n;i++)
    {
      cin>>b[i];
      if(a[i]!=b[i])
        f=0;
      if(a[i]>b[i])
        v.pb(mp(a[i],b[i]));
      if(a[i]<b[i])
        vv.pb(mp(a[i],b[i]));



      btotal+=b[i];
    }
    if(f)
      cout<<0<<endl;
    else if(atotal<btotal)
      cout<<-1<<endl;
    else
    {ll ans=0;
      sort(v.begin(), v.end(), sortbysec);
      sort(vv.begin(), vv.end(), sortbysec); 

     // for(auto t:v)cerr<<t.fi<<" "<<t.se<<endl;
        //for(auto t:vv)cout<<t.fi<<" "<<t.se<<endl;
          auto t=v.begin();
        auto tt=vv.begin();
        ll cur=0;
        while(tt!=vv.end())
        {
          cur+=t->fi-t->se;
         ans++;
         //cout<<"Cur = "<<cur<<endl;
         while(cur>0&&tt!=vv.end())
         {

           ll req=tt->se-tt->fi;
           ans++;
           if(req>cur)
           {
            while(cur<req)
            {
              t++;
              cur+=t->fi-t->se;
              ans++;
            }
           }
           cur-=req;
           tt++;
         }

       }

cout<<ans<<endl;

      }
}
return 0;
}