#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n,x;
  cin >> n >> x;
  int a = n;
  vector<int> m(n);
  rep(i,n) cin >> m[i];
  int minimum = 1e9;
  int sum = 0;
  rep(i,n) sum += m[i];
  rep(i,n){
   minimum = min(minimum,m[i]); 
  }
  x -= sum;
  int counts = x/minimum;
  cout << counts + a << endl;
}
