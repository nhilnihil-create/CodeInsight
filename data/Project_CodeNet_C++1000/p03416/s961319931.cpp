#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int num=0;
  for (int i = A; i<=B; i++){
    int s1, s2, s3, s4, s5;
    s1 = i / 10000;
    s2 = (i - s1*10000) / 1000;
    s3 = (i - s1*10000 - s2*1000) / 100;
    s4 = (i - s1*10000 - s2*1000 - s3*100) / 10;
    s5 = (i - s1*10000 - s2*1000 - s3*100 - s4*10) / 1;
    if (s1==s5 && s2 ==s4) {
      num++;
    }
  }
  cout << num << endl;
}