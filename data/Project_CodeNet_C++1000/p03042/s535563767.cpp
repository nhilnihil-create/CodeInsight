#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  bool zen = false, kou = false;
  if (N / 100 > 0 && N / 100 <= 12) zen = true;
  if (N % 100 > 0 && N % 100 <= 12) kou = true;
  if (zen && kou) puts("AMBIGUOUS");
  else if (zen) puts("MMYY");
  else if (kou) puts("YYMM");
  else puts("NA");
}