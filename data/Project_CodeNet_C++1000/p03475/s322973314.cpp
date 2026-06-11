#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
#define vi vector<int>
#define vvi vector<vi>
#define pii pair<int, int>
#define mod 1000000007
using ll = long long;
using namespace std;
int main(){
  int n;
  cin >> n;
  vi c(n - 1), s(n - 1), f(n - 1);
  rep(i, n - 1) cin >> c[i] >> s[i] >> f[i];
  rep(i, n - 1){
    int t = 0;
    for(int j = i; j < n - 1; j++){
      if(t < s[j]) t = s[j];
      else if(t % f[j] == 0);
      else t += f[j] - (t % f[j]);
      t += c[j];
    }
    cout << t << endl;
  }
  cout << 0 << endl;
}