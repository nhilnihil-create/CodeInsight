#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<ll,ll> pll;

const int mx=1e6+11;
const double PI = acos(-1);
#define MOD 1000000007


#define nl '\n'
#define pb push_back
#define F first
#define S second
#define I insert
#define mp make_pair

#define sz(x) x.size()
#define tt int t; cin>>t; while(t--)
#define lo(i,a,b) for(int i=a;i<b;i++)
#define be(a) (a).begin(),(a).end()
#define rbe(a) (a).rbegin(),(a).rend()
#define mem(a,b) memset(a,b,sizeof(a))

#define su ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define frac cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);

#define dbg(args...) do {cerr << #args << " : "; faltu(args); } while(0)
void faltu () {            cerr << endl;}
template < typename T, typename ... hello>void faltu( T arg, const hello &... rest) {cerr << arg << ' ';faltu(rest...);}


int main()
{
   su;
   ll n,m,x,y,sum=0;
   cin>>n>>m;
   pll p[n];
   lo(i,0,n)
   {
     cin>>x>>y;
     p[i]={x,y};
   }
   sort(p,p+n);
   for(int i=0;i<n;i++)
   {
     if(m<=0)
      break;
     else if(p[i].S<=m)
     {
       sum+=p[i].F*p[i].S;
       m-=p[i].S;
     }
     else
     {
       sum+=m*p[i].F;
       m=0;
     }
   }
   cout<<sum<<nl;
   return 0;
}
