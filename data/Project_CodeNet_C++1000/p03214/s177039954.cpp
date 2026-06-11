#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  int n,ans = 0,m = 1e5,p,av = 0;
  cin >> n;
  vector<int>a(n);
  rep(i,n){
    cin >> a[i];
    av += a[i];
  }
  rep(i,n){
    if(m > abs(av-n*a[i])){
      p = i;
      m = abs(av-n*a[i]);
    }
  }
  cout << p << endl;
}