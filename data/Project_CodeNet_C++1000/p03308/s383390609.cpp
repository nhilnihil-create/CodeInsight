#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main(){
  int n;
  cin >> n;
  vector<int> v(n);
  rep(i,n) cin >> v[i];

  int max = 0;
  int min = 1e9;
  rep(i,n){
    if (max < v[i]) max = v[i];
    if (min > v[i]) min = v[i];
  }
  cout << max - min << endl;
  return 0;
}