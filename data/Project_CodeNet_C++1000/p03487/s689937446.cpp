#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double dd;

typedef vector<int> vi;
typedef pair<int,int> pii;

const int mx=1e6+11;
const long double PI=3.14159265358979;

#define nl '\n'
#define pb push_back
#define F first
#define S second
#define I insert
#define mp make_pair

#define sz(x) x.size()
#define sqr(a) ((a) * (a))
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*(b/gcd(a,b)))
#define sa(v) sort(v.begin(),v.end())
#define sd(v) sort(v.begin(),v.end(),greater<>())
#define rev(s) reverse(s.begin(),s.end())
#define tt int t; cin>>t; while(t--)
#define lo(i,a,b) for(ll i=a;i<b;i++)
#define be(a) (a).begin(),(a).end()

#define yes cout<<"YES"<<nl;
#define no cout<<"NO"<<nl;

#define su ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

int main()
{
   su;
   int sum=0,n,a;
   cin>>n;
   map <int,int>m;
   while(n--)
   {
      cin>>a;
      m[a]++;
   }
   for(auto i:m)
   {
      n=i.F;
      a=i.S;
      if(n>a)
         sum+=a;
      else if(n<a)
         sum+=(a-n);
   }
   cout<<sum<<nl;
   return 0;
}
