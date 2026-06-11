#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int s;
  cin >> s;
  vector<int> a;
  int x = s;
  int cnt = 1;
  while(true){
    a.push_back(x);
    rep(i,a.size()-1){
       if(a.at(i) == x){
        cout << cnt << endl;
        return 0;
      }
    }
    if(x%2==0)  x /=2;
    else x = 3*x+1;
    cnt ++;
  }
 }
