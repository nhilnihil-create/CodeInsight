#include <bits/stdc++.h>
#include <set>
#define rep(i,n) for (int i=0; i < (n); ++i)
#define all(a) a.begin(), a.end()
using ll = long long;
using namespace std;
 
// ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }


// const double PI = acos(-1);


int main() {
  int N,T; cin >> N >> T;
  
  vector<int> c(N), t(N);
  rep(i,N) cin >> c[i] >> t[i];

  vector<int> c_empty;
  int ans=0;
  rep(i,N) {
    if (T >= t[i]) {
      c_empty.push_back(c[i]);
      ans++;
    }
  }
  if (ans ==0){
    cout << "TLE" << endl;
    return 0;
  }
      
  int c_min = c_empty[0];
  rep(i,c_empty.size()) {

    if (c_min > c_empty[i]) {
      c_min = c_empty[i];
    }

  }
  cout << c_min << endl;
  return 0;

 
}