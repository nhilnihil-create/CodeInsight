/* while(!success_achieved())
      work_hard();

   code by:aman_ayush
  */
#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define ldb long double 
#define db double
#define str string

#define fr first
#define se second
#define lb lower_bound 
#define ub upper_bound 
#define pb push_back
#define mp make_pair

#define pi pair<int,int>
#define pll pair<ll,ll>
#define pdb pair<db,db>
#define pldb pair<ldb,ldb>

#define vi vector<int>
#define vll vector<ll>
#define vdb vector<db>
#define vldb vector<ldb>
#define vpi vector< pi >
#define vpll vector< pll >

#define mi map<int,int>
#define mll map<ll,ll>
#define mdb map<db,db>
#define mldb map<ldb,ldb>


#define forr(a,b) for (int i = (a); i < (b); ++i)
#define rrof(a,b) for (int i = (b)-1; i >= (a); --i)

#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)

const int MOD = 1e9+7;
const int MX = 2e5+5;
const ll INF = 1e18; 
const ldb PI = 4*atan((ldb)1);

ll power(ll a,ll n)
{
 ll res=1;
 while(n)
{
 if(n%2)
  res*=a;
  a*=a;
  n/=2;
}
return res;
}

ll abst(ll a)
{
 return ((a<0)?(-1*a):(a));
}

int main()
{
     int m,k;
     cin>>m>>k;
     int p=power(2,m);
     if(k>=p)
      cout<<-1<<"\n";
      else
      {
          if(m==0)
           cout<<0<<" "<<0<<"\n";
           else if(m==1)
           {
               if(k==0)
                cout<<0<<" "<<0<<" "<<1<<" "<<1<<"\n";
               else 
                cout<<-1<<"\n";
           }
           else
           {
               for(int i=0;i<p;i++)
               {
                   if(i!=k)
                    cout<<i<<" ";
               }
               cout<<k<<" ";
               for(int i=p-1;i>=0;i--)
               {
                   if(i!=k)
                    cout<<i<<" ";
               }
                cout<<k<<" ";
                cout<<"\n";
           }
      }
     return 0;
}