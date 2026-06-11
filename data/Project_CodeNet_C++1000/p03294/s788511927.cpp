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
  vector<ll> a(n);
  rep(i,n) cin>>a[i];
  ll ans=0;
  rep(i,n) ans+=a[i]-1;
  cout<<ans<<endl;
return 0;
}