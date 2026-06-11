#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;;
  cin >> S;
  int N = S.size();
  int count1 =0; //白から始める
  int count2 =0; //黒から始める
  for (int i =0; i<N; i++) {
    if (i % 2 ==0) {
      if (S.at(i) == '0') count1++;
    }
    if (i % 2 ==1) {
      if (S.at(i) == '1') count1++;
    }
  }
  for (int i =0; i<N; i++) {
    if (i % 2 ==1) {
      if (S.at(i) == '0') count2++;
    }
    if (i % 2 ==0) {
      if (S.at(i) == '1') count2++;
    }
  }
  cout << min(count1,count2) << endl;
}