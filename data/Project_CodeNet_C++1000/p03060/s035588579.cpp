#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, ans;
  cin >> N;
  ans=0;
  vector<int> V(N);
  for (int i=0; i<N; i++) {
    cin >> V.at(i);
  }
  vector<int> C(N);
  for (int j=0; j<N; j++) {
    cin >> C.at(j);
  }
  vector<int> D(N);
  for (int k=0; k<N; k++) {
    D.at(k)=V.at(k)-C.at(k);
  }
  for (int l=0; l<N; l++) {
    ans=ans+max(D.at(l),0);
  }
  cout << ans << endl;
}
