#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007



int main(){
  
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  rep(i,n)cin >> a[i];
  rep(i,n)cin >> b[i];
  ll k = 0;
  rep(i,n)if(b[i] > a[i]){
    k += (b[i]-a[i])/2;
  }else{
    k += b[i]-a[i];
  }
  if(k >= 0)cout << "Yes" << "\n";
  else cout << "No" << "\n";

  





  return 0;
}