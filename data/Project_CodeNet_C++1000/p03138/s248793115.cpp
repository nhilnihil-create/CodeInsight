#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
typedef pair<ll,pair<ll,ll>>plll;
#define sf(a) scanf("%I64d",&a)
#define pf(a) printf("%I64d\n",a)
#define mem(a,b)     memset(a,b,sizeof(a))
#define vll(v) v.begin(),v.end()
#define all(x) x.rbegin(),x.rend()
#define F first
#define S second
#define minheap int,vector<int>,greater<int>
//#define mp make_pair
#define pb push_back
#define pp pop_back
#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))
#define ischar(x)  (('a' <= x && x <= 'z') || ('A' <= x && x <= 'Z'))
#define isvowel(ch) ((ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')||(ch=='A'|| ch=='E' || ch=='I'|| ch=='O'|| ch=='U'))
#define fastread() (ios_base:: sync_with_stdio(false),cin.tie(NULL));
#define in  freopen("input.txt", "r", stdin)
#define out  freopen("output.txt", "w", stdout)
const int Max_node = 7e6 + 10;
const int Mod = 1e9 + 7;
bool compare(const pair<int,int> &a, const pair<int,int> &b)
{
    return (a.first > b.first);
}
ll lcm(ll a,ll b)
{
    if(a==0 || b==0)
        return 0;

    return a/__gcd(a,b)*b;
}
//___________________________________________________________________________________________________________________
//                              CODE STARTS FROM HERE
//                               MU_Codefighter2018
//-------------------------------------------------------------------------------------------------------------------



ll cnt[Max_node][3];


void Insert(ll x)
{

    int now=0,i;

       for(i=63; i>=0; i--)
       {
           ll bit=(x>>i)&1ll;



          cnt[i][bit]++;


       }
}



ll Set(ll num, ll pos) {
        return num | (1LL << pos);
}


ll MAX(ll target)
{

    ll i,temp=0,sum=0;

        for(i=60; i>=0; i--)
       {




         if(cnt[i][0]<=cnt[i][1])
         {
             continue;
         }
         else
         {
             temp=sum;

           temp= Set(temp,i);



           if(temp<=target)
            sum=temp;




         }


       }

       return sum;
}

int main()
{
    fastread();



   ll i,j,n,m,p,a,sum=0,k,t,b,c,d,cnt=0,q,l,r,ans=0;

      bool flag=false;

      string str;


      cin>>n>>k;


      ll ara[n+2];

      for(i=0; i<n; i++)
      {
          cin>>ara[i];

          Insert(ara[i]);
      }

      ll mx=MAX(k);

     // cout<<mx<<endl;


      for(i=0; i<n; i++)
      {
          sum+=(ara[i]^mx);
      }

      cout<<sum<<endl;









}
