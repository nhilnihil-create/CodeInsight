#include <bits/stdc++.h>
#define rep(i,n)for(long long i=0;i<(n);i++)
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
const int MAX = 1000000;
const int INF = 1e9;
const double pi=acos(-1);
using namespace std;

int main(){
  int n; 
  cin >> n;
  ll cnt=0;
  vector<ll>a(n),b(n);
  rep(i,n) cin >> a[i];
  rep(i,n) cin >> b[i];
  rep(i,n){
    if(a[i]-b[i]>0)cnt-=a[i]-b[i];
    if(b[i]-a[i]>0)cnt+=(b[i]-a[i])/2;
  }
  if(cnt>=0)cout<<"Yes"<<endl;
  else cout <<"No"<<endl;
  return 0;
}