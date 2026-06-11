//...Hare..Krishna..//
//...Hare..Krishna...//
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double d;

#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (abs(a*b)/gcd(a,b))
#define sqr(a) (a*a)

#define tt int t; cin>>t; while(t--)
#define lo(i, a, b) for(int i=a; i<=b; i++)
#define rlo(i, a) for(int i=a; i>0; i--)
#define be(a) a.begin(),a.end()
#define sz(x) x.size();
#define nl cout<<"\n";
#define sp cout<<" ";
#define Y cout<<"YES"<<endl;
#define N cout<<"NO"<<endl;
#define nlng long long n; cin>>n;
#define nint int n; cin>>n;
#define br break;
#define cn continue;
#define vec vector < int >
#define vecll vector < long long >
#define op() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int main()
{
    op();
   string u;
   double s=0.0,x;int n;
   cin>>n;
   for(int i=1;i<=n;i++)
   {
       cin>>x>>u;
      
       if(u=="BTC")
       {
           x=x*380000.0;

       }
       s=s+x;
   }
 std::cout<<setprecision(8)<<fixed<<s<<endl;
    return 0;
}


