#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> pri(100010, 1), like(100010), sum(100010);
  for(int i = 2; i * 2 <= 100010; i++){
    for(int j = i + i; j < 100010; j += i) pri.at(j) = 0;
  }
  for(int i = 3; i < 100010; i++){
    if(!pri.at(i)) continue;
    if(pri.at((i+1)/2)) like.at(i) = 1;
  }
  int cnt = 0;
  for(int i = 0; i < 100010; i++){
    if(like.at(i)) cnt++;
    sum.at(i) = cnt;
  }
  
  int q;
  cin >> q;
  for(int i = 0; i < q; i++){
    int l, r;
    cin >> l >> r;
    cout << sum.at(r) - sum.at(l-1) << endl;
  }
}