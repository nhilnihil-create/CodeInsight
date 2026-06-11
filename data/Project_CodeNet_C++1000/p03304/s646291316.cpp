#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int main(){

  ll n,m,d;
  cin >> n >> m >> d;
  cout << fixed << setprecision(20);
  if(d == 0){
    cout << (double)1/n*(m-1) << endl;
  }else{    
    if(2*d >= n){
      cout << (double)1/n*(m-1) << endl;
    }else{
      cout << (double)2*(n-d)/n/n*(m-1) << endl;
    }
  }





  return 0;
}