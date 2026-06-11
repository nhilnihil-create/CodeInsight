// I SELL YOU...! 
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<chrono>
#include<iomanip>
#include<map>
#include<set>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
void init_io(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << setprecision(10);
}
signed main(){
  init_io();
  ll n,ans=0,mb=10000000000000;
  bool all=true;
  cin >> n;
  vector<ll> a(n),b(n);
  vector<P> ab;
  for(int i=0;i<n;i++){
    cin >> a[i] >> b[i];
    ans += a[i];
    if(a[i]!=b[i]) all = false;
  }
  if(all){
    cout << "0\n";
    return 0;
  }
  for(int i=0;i<n;i++){
    if(a[i]>b[i]){
      mb = min(mb,b[i]);
    }
  }
  cout << ans - mb<<endl;
}
