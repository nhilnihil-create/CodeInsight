#include <bits/stdc++.h>
using namespace std;

int main() {
  string S; cin >> S;
  int count =0; int countMax =0;
  int N = S.size();
  for (int i =0; i<N; i++) {
    if (S.at(i) == 'A' || S.at(i) == 'C' || S.at(i) == 'G' || S.at(i) == 'T') {
      count++;
    } else {
      countMax = max(count,countMax);
      count =0;
    }
    countMax = max(count,countMax);
  }
  cout << countMax << endl; 
}
