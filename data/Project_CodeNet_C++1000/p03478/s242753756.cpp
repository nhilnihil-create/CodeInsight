#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, A, B;
  cin >> N >> A >> B;
  
  int count = 0;
  for (int i = 1; i <= N; i++) {
    string S = to_string(i);
    if (i < 10) {
      int a = stoi(S);
      if (A <= a && a <= B) count += i;
    }
    else if (10 <= i && i < 100) {
      string p, q;
      p = S.at(1);
      q = S.at(0);
      int a = stoi(p);
      int b = stoi(q);
      if (A <= a+b && a+b <= B) count += i;
    }
    else if (100 <= i && i < 1000) {
      string p, q, r;
      p = S.at(2);
      q = S.at(1);
      r = S.at(0);
      int a = stoi(p);
      int b = stoi(q); 
      int c = stoi(r);
      if (A <= a+b+c && a+b+c <= B) count += i;
    }
    else if (1000 <= i && i < 10000) {
      string p, q, r, s;
      p = S.at(3);
      q = S.at(2);
      r = S.at(1);
      s = S.at(0);
      int a = stoi(p);
      int b = stoi(q); 
      int c = stoi(r);
      int d = stoi(s);
      if (A <= a+b+c+d && a+b+c+d <= B) count += i;
    }
    else if (i = 10000) {
      string p, q, r, s, t;
      p = S.at(4);
      q = S.at(3);
      r = S.at(2);
      s = S.at(1);
      t = S.at(0);
      int a = stoi(p);
      int b = stoi(q); 
      int c = stoi(r);
      int d = stoi(s);
      int e = stoi(t);
      if (A <= a+b+c+d+e && a+b+c+d+e <= B) count += i;
    }
  }
  cout << count << endl;
}
