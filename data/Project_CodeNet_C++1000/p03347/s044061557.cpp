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
  vector<int> v(n);
  rep(i,n)cin >> v[i];
  ll res = 0;
  rep(i,n){
    if(v[i] > i || (i-1 >= 0 && v[i] > v[i-1]+1)){
      cout << -1 << endl;
      return 0;
    }else{
      if(i-1 >= 0 && v[i] == v[i-1]+1){
        res++;
      }else{
        res += v[i];
      }
    }
  }
  cout << res << endl;









  return 0;
}