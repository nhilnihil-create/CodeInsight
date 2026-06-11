/*
    -ensure correct output format
    -ensure printing required output
    -reread the problem statement
  */

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
const int Max =2999+20;
const int Mod = 1e9 + 7;
const double PI  =3.141592653589793238463;
bool compare(const pair<ll,ll> &a, const pair<ll,ll> &b)
{
       return (a.first > b.first);
}
ll lcm(ll a,ll b)
{
    if(a==0 || b==0)return 0;

    return a/__gcd(a,b)*b;
}

void input(ll ara[],ll n)
{
    for(ll i=0; i<n; i++)cin>>ara[i];
}

double dp[Max][Max];

ll n;


double ara[Max+10];
bool vis[Max+10][Max+10];

double call(int i,int head)
{
    double &ret=dp[i][head];

    if(head<0)return 0.0;


 //     vis[i][head]=true;

      if(i<0)
       return (head==0);

        if(vis[i][head])return ret;


        vis[i][head]=true;

       ret=(ara[i]*call(i-1,head-1))+((1.0-ara[i])*call(i-1,head));

       return ret;


}


int main()
{

   fastread();

   ll i,j,m,p,a,sum=0,k,t,b,c,d,cnt=0,q,l,r;

      bool flag=false;

      memset(dp,0,sizeof(dp));
      memset(vis,false,sizeof(vis));

      cin>>n;

      for(i=0; i<n; i++)
        cin>>ara[i];


        double ans=0;
    for(ll head=0; head<=n; head++)
    {
        ll tail=n-head;

       // cout<<head<<" "<<tail<<endl;
        if(head>tail)
            {
                ans+=call(n-1,head);

                //cout<<head<<endl;
            }
    }

    cout<<setprecision(9)<<fixed<<ans<<endl;




}
