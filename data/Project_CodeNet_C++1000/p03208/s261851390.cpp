#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> h(N);
  for (int i=0; i<N; i++) {
    cin >> h.at(i);
  }
  sort(h.begin(),h.end());
  vector<int> d(N-1);
  for (int j=0; j<N-1; j++) {
    d.at(j)=h.at(j+1)-h.at(j);
  }
  vector<int> s(N-K+1);
  for (int k=0; k<N-K+1; k++) {
    s.at(k)=d.at(k);
    for (int l=1; l<K-1; l++) {
      s.at(k)=s.at(k)+d.at(k+l);
    }
  }
  sort(s.begin(),s.end());
  cout << s.at(0) << endl;
}
