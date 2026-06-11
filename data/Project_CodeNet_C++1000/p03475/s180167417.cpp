#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<int>c(n-1);
  vector<int>s(n-1);
  vector<int>f(n-1);
  rep(i,0,n-1) cin >> c[i] >> s[i] >> f[i];
  rep(i,0,n){
    int t = 0;
    rep(j,i,n-1){
      if(t < s[j]) t = s[j];
      else if(t%f[j] == 0);
      else t = t+f[j]-t%f[j];
      t += c[j];
    }
    cout << t << endl;
  }
}