#include<bits/stdc++.h>
using namespace std;
typedef     long long    ll;
typedef     vector<int> vi;
typedef     vector<long long> vl;
typedef     pair<int, int>pi;
typedef     pair<long long, long long>pl;
#define F   first
#define S   second
#define pb  push_back
#define     all(x)      x.begin() , x.end()
#define mp  make_pair
#define       FOR(i,a,b) for(i=a;i<=b;i++)
#define     mem(a)      memset(a , 0 ,sizeof a)
#define     memn(a)     memset(a , -1 ,sizeof a)
ll ck[100000];
int main()
{
  int t;
  t=1;
  //cin >> t;
  while (t--)
  {
      ll n,d,i,j,x,y,mx=INT_MIN,mn=INT_MAX;
      cin>>n>>d;
       FOR(i,1,d)
       {
        cin>>x>>y;
        mx=max(mx,x);
        mn=min(mn,y);
       }
       cout<<max(ll(0),(mn-mx)+1)<<endl;
  }
}