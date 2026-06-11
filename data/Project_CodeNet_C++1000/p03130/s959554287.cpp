#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
  vector<int>p(4);
  int o = 0,t = 0;
  rep(i,6){
    int a;
    cin >> a;
    a--;
    p[a]++;
  }
  rep(i,4){
    if(p[i] == 1) o++;
    if(p[i]== 2) t++;
  }
  if(o == 2 && t == 2) cout << "YES" << endl;
  else cout << "NO" << endl;
}