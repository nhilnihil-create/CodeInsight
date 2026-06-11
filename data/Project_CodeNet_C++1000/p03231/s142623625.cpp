#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long 
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


    ll n,m,f=0;
    cin>>n>>m;
    ll gd=gcd(1ll*n,1ll*m);
    ll lcm=1ll*n/gd * 1ll*m;
   
    //cerr<<lcm<<endl;
    string s,t;
    cin>>s>>t;
   // cout<<s<<" "<<t<<endl;
    if(s[0]!=t[0])
    {
      cout<<-1<<endl;
    }
    else
    {
      map<ll,char>mm;
      vi v,vv;

      
      for(int i=1;i<n;i++)
      {
           ll p=i*(lcm/n);
           v.pb(p);
      }
      for(int i=1;i<m;i++)
      {
        ll p=i*(lcm/m);
        vv.pb(p);
        
      }
      sort(v.begin(),v.end());sort(vv.begin(),vv.end());
      /*for(auto tt:v)cout<<tt<<" ";
        cout<<endl;
      for(auto tt:vv)cout<<tt<<" ";
        cout<<endl;*/
      ll size=max(v.size(),vv.size());
      vector<ll> combo(size); 
    vector<ll>::iterator it, st; 
      it = set_intersection(v.begin(), 
                          v.end(), 
                          vv.begin(), 
                          vv.end(), 
                          combo.begin()); 
      //for(auto tt:combo)cout<<tt<<" ";
        //cout<<endl;
      for(int i=0;i<combo.size();i++)
      {
        if(combo[i]==0)
        {
          break;
        }
        else
        {
          ll x=lcm/n;
          ll p=combo[i]/x;
          ll y=lcm/m;
          ll q=combo[i]/y;
          //cout<<"P = "<<p<<" Q = "<<q<<endl;
          if(s[p]!=t[q])
          {
            //cout<<"IFFFFFF "<<s[p]<<" "<<t[q]<<endl;
            f=1;
            break;
          }
        }
      }
  
    //cout<<"F "<<f<<endl;
      if(f)
      {
        cout<<-1<<endl;
      }
      else
      {
        cout<<lcm<<endl;
      }
    
    
  }


return 0;
}
