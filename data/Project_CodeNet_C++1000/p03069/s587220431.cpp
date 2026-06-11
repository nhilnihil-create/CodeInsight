#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main(){
  int n; cin >> n;
  string s; cin >> s;
  int w = 0, b;
  rep(i, n){
    if(s[i] == '.') w++;
  }
  b = n - w;
  int ans = w, sum = 0, tmp;
  rep(i, n){
    if(s[i] == '.'){
      w--;
      tmp = sum + w;
    }
    else{
      sum++;
      tmp = sum + w;
    }
    ans = min(ans, tmp);
  }
  cout << ans << endl;
  return 0;
}
