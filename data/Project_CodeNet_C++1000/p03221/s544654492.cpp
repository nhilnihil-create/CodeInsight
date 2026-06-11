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
const int Max = 2e6 + 10;
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
void print(ll ara[],ll n)
{
    for(ll i=0; i<n; i++)
        cout<<ara[i]<<" ";
    cout<<endl;
}



vector<pll>adj[Max];

int main()
{

   fastread();

   ll i,j,n,m,p,a,sum=0,k,b,c,d,cnt=0,q,l,r;

      bool flag=false;

      string str;






  cin>>n>>m;

  vector<pll>v;

 pair<string,string> Ans[m+2];


  for(i=0; i<m; i++)
  {
   cin>>a>>b;

   v.eb(a,b);

   adj[a].eb(b,i);

   d=log10(a)+1;


           string temp=to_string(a);

           for(ll j=0; j<6-d; j++)
                        temp="0"+temp;


           Ans[i].F=temp;
  }

   for(i=1; i<=n; i++)
   {
       sort(vll(adj[i]));

       cnt=1;

       for(auto x : adj[i])
       {

           d=log10(cnt)+1;

           string temp=to_string(cnt);;

           for(j=0; j<6-d; j++)
                        temp="0"+temp;


           Ans[x.S].S=temp;




           cnt++;
       }
   }

   for(i=0; i<m; i++)
   {
       cout<<Ans[i].F<<""<<Ans[i].S<<endl;
   }






}

