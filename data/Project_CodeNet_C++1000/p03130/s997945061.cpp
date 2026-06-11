#include <bits/stdc++.h>
using namespace std;
int main(){
  vector<int> p(4, 0);
  bool flg = true;
  for (int i = 0; i < 3; i++){
    int a, b;
    cin >> a >> b;
    p[a - 1]++;
    p[b - 1]++;
    if (p[a - 1] == 3){
      flg = false;
    }
    if (p[b - 1] == 3){
      flg = false;
    }
  }
  cout << (flg ? "YES" : "NO");
}