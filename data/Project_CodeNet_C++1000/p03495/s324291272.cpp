#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k, kakikae = 0;
  cin >> n >> k;
  map<int, int> a;//valueは登場回数
  for (int i = 0; i < n; i++) {
    int ai; cin >> ai;
    if (a.count(ai)) a[ai]++;
    else a[ai] = 1;
  }
  int syurui = a.size(); //a.size()→kにしたい
  if (syurui <= k) goto OUT; 
  for (int i = 1; i < n; i++) {//まずは1回しか出て来ないやつから消したい
    for (auto p: a) {
      if (p.second == i) {
        syurui--;
        kakikae += i;
        if (syurui <= k) goto OUT; 
      }
    }
  }
  OUT:
  cout << kakikae;
}