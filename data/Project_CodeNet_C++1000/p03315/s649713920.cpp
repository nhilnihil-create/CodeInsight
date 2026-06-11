#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;
const int inf = 1001001001;

int main(){
  string s;
  cin >> s;
  int ans = 0;
  rep(i,4) {
    if(s.at(i) == '+') ans++;
    else ans--;
  }
  cout << ans << endl;
}
