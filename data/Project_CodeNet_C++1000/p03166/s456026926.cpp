#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll>pll;
typedef pair<ll,pair<ll,ll>>plll;
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define vll(v) v.begin(),v.end()
#define all(x) x.rbegin(),x.rend()
#define min3(a, b, c)   min(a, min(b, c))
#define max3(a, b, c)   max(a, max(b, c))
#define F first
#define S second
#define in  freopen("input.txt", "r", stdin)
#define out  freopen("output.txt", "w", stdout)
#define minheap int,vector<int>,greater<int>
#define pb push_back
#define eb emplace_back
#define ischar(x)  (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'))
#define isvowel(ch) ((ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')||(ch=='A'|| ch=='E' || ch=='I'|| ch=='O'|| ch=='U'))
#define bug cout<<"BUG"<<endl;
const int Max = 1e5 + 10;
const int Mod = 1e9 + 7;
const double PI  =3.141592653589793238463;


ll n,m;

vector<ll>adj[Max+10];

ll indeg[Max+10];

ll dis[Max+10];



void input()
{
      ll i,a,b;


       for(i=1; i<=m; i++)
       {
           cin>>a>>b;

           adj[a].eb(b);

           indeg[b]++;
       }
}

ll topsort()
{
    ll u,mx=0;

       queue<ll>q;

       for(ll i=1; i<=n; i++)
       {
           if(!indeg[i])q.push(i);
       }

         while(!q.empty())
         {
              u=q.front();

              q.pop();

                for(auto v  : adj[u])
                {
                   dis[v]=max(dis[v],dis[u]+1);

                   mx=max(dis[v],mx);

                   indeg[v]--;

                   if(!indeg[v])
                    q.push(v);
                }
         }

         return mx;
}
int main()
{

   fastread();

   ll i,j,p,a,sum=0,k,t,b,c,d,cnt=0,q,l,r;


     string str;

   bool flag=true;

     cin>>n>>m;

     input();


      cout<<topsort()<<endl;







}

