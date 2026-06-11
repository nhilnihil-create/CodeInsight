#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;

  if(n==1){
    cout << 0 << endl;
    return 0;
  }

  vector<int> c(n);
  vector<int> s(n);
  vector<int> f(n);

  rep(i,n-1) cin >> c[i] >> s[i] >> f[i];

  rep(i,n-1){
    int t = s[i] + c[i];
    for(int j = i + 1; j < n-1; j++){
      if(s[j] > t) t = s[j] + c[j];
      else{
        int tmp = s[j];
        while(t>tmp){
          tmp += f[j];
        }
        t = tmp + c[j];
      }
    }
    cout << t << endl;
  }

  cout << 0 << endl;

  return 0;
}
