#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;
ll MOD=1000000007;
int main(){
  ll n,h;
  cin>>n>>h;
  vector<ll> a(n);
  vector<ll> b(n);
  rep(i,n) cin>>a[i]>>b[i];
  sort(all(a));
  sort(all(b));
  reverse(all(b));
  ll amax=a[n-1];
  ll count=0;
  rep(i,n){
    if(b[i]>amax&&h>0){
      h-=b[i];
      count++;
    }
  }
  if(h>0){
  cout<<count+(h+amax-1)/amax;
    return 0;
  }
else cout<<count;
return 0;
}