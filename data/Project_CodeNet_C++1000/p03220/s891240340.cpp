/// --- In the name of ALLAH --- ///


#include <cmath>
#include<bits/stdc++.h>
using namespace std;


typedef long long              ll;
typedef vector<int>            vi;
typedef vector<ll>             vl;
typedef vector<vi>             vvi;
typedef vector<vl>             vvl;
typedef pair<int,int>          pii;
typedef pair<double, double>   pdd;
typedef pair<ll, ll>           pll;
typedef vector<pii>            vii;
typedef vector<pll>            vll;
typedef double                 dl;

#define endl                   '\n'
#define PB                     push_back
#define F                      first
#define S                      second
#define all(a)                 (a).begin(),(a).end()
#define rall(a)                (a).rbegin(),(a).rend()
#define sz(x)                  (ll)x.size()
#define wt                     ll t; cin>>t; while(t--)
#define input(a,n)             for(int i=0;i<n;i++) cin>>a[i];

const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;


#define mem(a,b) memset(a, b, sizeof(a) )
#define sqr(a) ((a) * (a))
#define mod 10000007
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}

ll gcd ( ll a, ll b ) { return __gcd ( a, b ); }
ll lcm ( ll a, ll b ) { return a * ( b / gcd ( a, b ) ); }


const ll mx=1e9;



//q=51;

//ll b[q+1][q+1];


 main()
{
    optimize();
   ll t,n,a,i,in;
   cin>>n>>t>>a;
   ll h[n+1];
   double b[n+1],j,mi;
   for(i=1;i<=n;i++)
   {
       cin>>h[i];
       b[i]=t-(h[i]*(0.006));
       //cout<<b[i]<<endl;
   }
   for(i=1;i<=n;i++)
   {
       if(b[i]>a)
       {
           j=b[i]-a;
           if(i==1){
            mi=j;
            in=1;}
           else if(j<mi)
           {
               mi=j;
               in=i;
           }


       }
       else
       {
           j=a-b[i];
           if(i==1){
            mi=j;
            in=1;}
           else if(j<mi)
           {
               mi=j;
               in=i;
           }


       }

   }
   cout<<in<<endl;



    return 0;
}




























































































