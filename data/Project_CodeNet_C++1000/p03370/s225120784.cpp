#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(x) cout << fixed << setprecision(x);
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;
 
 
int main(){
  ll N,X;
  cin >> N >>X;
  vl vec(N);
  rep(i,N){
    cin >> vec.at(i);
  }
  ll ans = X;
  rep(i,N){
    ans -=vec.at(i);
  }
sort(vec.begin(), vec.end());
  
  ll ANZ = ans /vec.at(0);
  
  cout << ANZ +N<< endl;
}
  