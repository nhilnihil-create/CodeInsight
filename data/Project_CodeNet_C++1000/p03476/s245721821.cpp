#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const ll M = 1e9 + 7;

int main() {
  int q;
  cin >> q;

  vector<bool> v(1e5+10,true);
  v[0] = false;
  v[1] = false;
  for (int i = 2; i < v.size(); i++){
    if (v[i] == false) continue;
    for(int j = 2*i; j < v.size(); j += i){
      v[j] = false;
    }
  }

  vector<bool> x(1e5+10, false);
  for (int i = 2; i < x.size(); i++){
    if ((v[i] == true) && (v[(i+1)/2] == true)) x[i] = true;
  }

  vector<int> a(1e5+10,0);
  for (int i = 1; i < a.size(); i++){
    if (x[i] == true) a[i] = a[i-1] + 1;
    else a[i] = a[i-1];
  }

  rep(i,q){
    int l, r;
    cin >> l >> r;
    cout << a[r] - a[l-1] << endl;
  }
  
  return 0;
}
