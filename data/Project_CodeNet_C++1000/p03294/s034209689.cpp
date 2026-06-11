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


ll mp[Max];


void primefact(ll n)
{

    ll cnt=0;

    while(n%2==0)
    {
        n/=2;
        cnt++;
    }

    mp[2]=max(mp[2],cnt);

    cnt=0;


    for(ll i=3; i<=sqrt(n); i+=2)
    {
        cnt=0;

            while(n%i==0)
            {
                n/=i;

                cnt++;
            }

            mp[i]=max(mp[i],cnt);

    }

    if(n>2)
        mp[n]=max(mp[n],1ll);
}
ll power(ll x, ll y)
{
    if (y == 0)
        return 1;
    else if (y%2 == 0)
        return power(x, y/2)*power(x, y/2);
    else
        return x*power(x, y/2)*power(x, y/2);
}
int main()
{

   fastread();

   ll i,j,n,m,p,a,sum=0,k,t,b,c,d,cnt=0,q,l,r,ans=0,dasdasdads;

      bool flag=false;

      string str;


        cin>>n;

        ll ara[n+2];

        input(ara,n);

        sum=accumulate(ara,ara+n,0);


        cout<<sum-n<<endl;













}
