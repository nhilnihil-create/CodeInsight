#include <bits/stdc++.h>
using namespace std;
 
#define clr(i, j)     memset(i, j, sizeof(i))
#define pb            push_back
 #define PI acos(-1)
 #define MOD ((int)1e9+7)
typedef long long     ll;
 
//-*-*-*-*-*-*-*-*-
 
 

 
const int N=2e5+100;
ll visited[100005];
//ll a[200000];
 

#define lop(i,n) for(int i=0;i<n;++i)
//ll n,m,mod;

int dx[4] = {1 , 0 , 0 , -1} ;
int dy[4] = {0 , 1 , -1 , 0} ;

const int MAX = 2e5 + 10 ;
void finis(){cout<<-1;}
vector<ll>v[1000000];


ll h,w,n,m;

int main()
{  ios::sync_with_stdio(0);
cin.tie(0);
cin>>n>>m;
ll lol=0;ll ans=0;ll sum=0;
for(int i=1;i<=m;i++){
    ll x,y;
   cin>>x>>y;
 ll xx=max(x,y);ll yy=min(x,y);
 v[xx].push_back(yy);
   
}ll mx=-11;
for(int i=n;i>=1;i--){
  if(i==mx){ans++;mx=-111;}
  for (ll j:v[i]){
      mx=max(j,mx);
  }
}
cout<<ans;
}
