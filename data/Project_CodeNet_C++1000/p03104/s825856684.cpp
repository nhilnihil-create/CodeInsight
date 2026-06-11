#include <bits/stdc++.h>

#define ll long long int
#define pf push_front
#define mod  1000000007
#define inf  1000000000000000000
#define pi  acos(-1.0)
#define maxn  1000009
#define endl '\n'
#define sorted(s)  sort(s.begin(),s.end())
#define reversed(s) reverse(s.begin(),s.end())
#define sortarr(a) sort(a,a+n)
#define slc(n) scanf("%I64d", &n)
#define sl(n)  scanf("%lld", &n)
#define sf(n)  scanf("%lf", &n)
#define si(n)  scanf("%d", &n)
#define sch(n)  scanf(" %c", &n)
#define ss(n)  scanf("%s", n)
#define prf printf
#define pb  push_back
#define fr first
#define sc second
#define all(a)  a.begin(),a.end()
#define forl(n) for(i=0;i<n;i++)
#define ison(n,j) (n&(1LL<<j))
#define _fastio  ios_base:: sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;

int main()
{
   ll a,b,x,y,res;
   cin>>a>>b;
   if(a%2)
    x=a+1;
   else
    x=a;
   if(b%2)
    y=b;
   else
    y=b-1;
   if(((y-x+1)/2)%2)
    res=1;
   else
    res=0;
   if(a%2)
    res=res^a;
   if(b%2==0)
    res=res^b;
   cout<<res<<endl;

    return 0;
}