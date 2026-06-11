#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, yen = 0;//yen答え、マイナスになるくらいなら適当なやつ言って0円
  cin >> n;
  map<string, int> s;//値は基本1もしダブったら数増やす
  for (int i = 0; i < n; i++) {
    string si;
    cin >> si;
    if (s.count(si)) s[si]++; 
    else s[si] = 1;
  }
  cin >> m;
  map<string, int> t;//値は基本-1ダブったら数減らす
  for (int i = 0; i < m; i++) {
    string ti;
    cin >> ti;
    if (t.count(ti)) t[ti]--; 
    else t[ti] = -1;
  }
  for (auto p: s) {
    if (!t.count(p.first)) yen = max(yen, p.second);
    else yen = max(yen, p.second + t[p.first]);
  }
  cout << yen;
}