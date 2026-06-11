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
bool sortinrev(const pair<ll,ll> &a,  
               const pair<ll,ll> &b) 
{ 
       return (a.first > b.first); 
}
int main() {
   /* #ifndef ONLINE_JUDGE
        // for getting input from input.txt
        freopen("input.txt", "r", stdin);
        // for writing output to output.txt
        freopen("output.txt", "w", stdout);
    #endif*/
        /* 
        Ofcourse it's Hard.
        It's supposed to be Hard.
        If it's easy everyone would do it.
        HARD IS WHAT MAKES IT GREAT

        YESTERDAY U SAID TOMORROW

        SLOWLY BECOMING THE PERSON I 
        SHOULD HAVE BEEN A LONG TIME AGO

        SAME TASK CAN'T BE FOUND DIFFICULT TWICE

        BTBHWSITW

        SPRH TU KAB P

        CP IS ALL ABOUT THINKING 
        YOU HAVE MUCH MORE POTENTIAL THAN U THINK

        AJIT SHIDDAT 10

        UR DAILY ROUTINE 


        */

fast();
//ll t;cin>>t;while(t--)
{
    ll n,c=0;
    cin>>n;
    ll a[n];
    set<ll>st;
    map<ll,ll>o,e;
    for(int i=0;i<n;i++)
    {
      cin>>a[i];
      st.insert(a[i]);
    }
    for(int i=0;i<n;i++)
    {
      
      if(i%2==0)
      {
        e[a[i]]++;
      }
      else
      {
        o[a[i]]++;
      }
    }
    vector<pair<ll,ll> >vo,ve;
    for(auto t:e)
      ve.pb(mp(t.se,t.fi));
    for(auto t:o)
      vo.pb(mp(t.se,t.fi));
   // for(auto t:e)if(t.se==12453)cout<<t.fi<<endl;
      //cout<<"&&&&"<<endl;
      //for(auto t:o)if(t.se==12453)cout<<t.fi<<endl;
   
      
    sort(vo.begin(),vo.end(),sortinrev);
    sort(ve.begin(),ve.end(),sortinrev);

    auto it=vo.begin();
    auto itt=ve.begin();
    auto ttt=itt;
    auto tat=it;
    //cout<<"hiji "<<tat->fi<<"  "<<tat->se<<endl;
    //cout<<"hiji "<<ttt->fi<<"  "<<ttt->se<<endl;
    tat++;ttt++;
    //cout<<"hiji "<<tat->fi<<"  "<<tat->se<<endl;
    //cout<<"hiji "<<ttt->fi<<"  "<<ttt->se<<endl;
    ll f=0,s=0;
    if(it->se==itt->se)
    { //cout<<"Hello"<<endl;
          if(it->fi>itt->fi)
          {
            f=it->fi;
            itt++;
            s=itt->fi;
          }
          else if(it->fi<itt->fi)
          {
            f=itt->fi;
            it++;
            s=it->fi;
          }
          else
          {
            auto its=it;
            its++;
            auto itts=itt;
            itts++;
            if(its->fi>itts->fi)
            {
              f=itt->fi;
              s=its->fi;
            }
            else if (its->fi<itts->fi)
            {
              f=it->fi;
              s=itts->fi;
            }
            else
            {
              f=it->fi;
              s=itts->fi;
            }
          }
    }
    else
    {
      f=it->fi;
            //itt++;
            s=itt->fi;

    }
     //cerr<<vo[0]<<"  "<<ve[0]<<endl;
  
     {
   
      if(st.size()==2)
      {
        cout<<0<<endl;
      }
      else if(st.size()==1)
        {//cout<<"two"<<endl;
          cout<<n/2<<endl;}
      else
        {
          //cout<<"three"<<endl;
          f=max(0ll,n/2-f);
          s=max(0ll,n/2-s);
          cout<<(f+s)<<endl;
        }
      }
}
return 0;
}