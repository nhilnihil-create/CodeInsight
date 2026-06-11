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
    string s,t,u;
    ll i,n,c=0;

    cin>>s>>t;
    n=sz(s);
    if(s==t)
        cout<<"Yes"<<endl;
    else
    {
       u=s;
       for(i=0;i<n;i++)
       {
           u=u.back()+u;
           u.pop_back();
           if(u==t)
           {
               c++;
               cout<<"Yes"<<endl;
               break;
           }
       }
       if(c==0)
        cout<<"No"<<endl;
    }









    return 0;
}




























































































