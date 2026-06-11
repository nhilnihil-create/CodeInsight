#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) rep2(i, 0, n)
#define rep2(i, m, n) for (ll i = m; i < (n); i++)

using ll = long long;
using pii = pair<int, int>;
using Vi = vector<int>;


int main() {
  int n;
  cin >> n;
  vector<int> v(100,0);
  
  rep(i,n){
    cin >> v[i];
  }
  
  sort(v.begin(), v.end());
  reverse(v.begin(), v.end());
  int A = 0;
  int B = 0;
  rep(i,50){
    A += v[2*i];
    B += v[2*i+1];
  }
  
  cout << A-B << endl;
}