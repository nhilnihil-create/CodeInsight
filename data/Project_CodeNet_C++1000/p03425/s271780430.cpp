#include <bits/stdc++.h>
typedef long long ll;
#define fr(i,a,b) for(ll i=a; i<b; i++)
#define rf(i,a,b) for(ll i=a; i>=b; i--)
typedef std::vector<long long > vi ;
#define F first
#define S second
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define mod 1000000007
#define PB push_back
#define MP make_pair
#define PI 3.14159265358979323846
#define all(a) a.begin(),a.end()
#define mx(a) *max_element(all(a))
#define mn(a) *min_element(all(a))
#define endl '\n'
#define show(a) for(auto el:a)cout<<el<<" "
const ll INF=LLONG_MAX/2;
const ll N=2e5+1;
#define yesno(f) yes(f);no(f);
#define yes(f) if(f)cout<<"YES\n";
#define no(f) if(!f)cout<<"NO\n";
using  namespace std;
int main()
{
    fast;
   ll t=1;
   //std::cin >> t;
   while(t--)
   {
       ll n,i,j=0,m=0,a=0,r=0,c=0,h=0;
       std::cin >> n;
       string s[n];
       fr(i,0,n)
       {
           std::cin >> s[i];
           if(s[i][0]=='M')
           m++;
           if(s[i][0]=='A')
           a++;
           if(s[i][0]=='R')
           r++;
           if(s[i][0]=='C')
           c++;
           if(s[i][0]=='H')
           h++;
       }
       ll x[5],sum=0;
       x[0]=m,x[1]=a,x[2]=r,x[3]=c,x[4]=h;
       fr(i,0,5)
       {
           fr(j,i+1,5)
           {
               fr(l,j+1,5)
               {
                   sum+=(x[i]*x[j]*x[l]);
               }
           }
       }
       cout<<sum<<"\n";
   }
}