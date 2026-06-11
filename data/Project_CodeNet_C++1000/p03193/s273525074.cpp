#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep2(i,m,n) for(int (i)=(m);(i)<(n);(i)++)
#define ll long long
#define ld long double
#define all(a) (a).begin(),(a).end()
#define mk make_pair
int main(){
int n;
  cin>>n;
ll h,w,a,b;
  cin>>h>>w;
  vector<pair<ll,ll>> p(n);
  rep(i,n){
    cin>>a>>b;
    p[i]=mk(a,b);
  }
  int ans=0;
  rep(i,n){
    if(p[i].first>=h&&p[i].second>=w) ans++;
  }
  cout<<ans<<endl;
  return 0;
}