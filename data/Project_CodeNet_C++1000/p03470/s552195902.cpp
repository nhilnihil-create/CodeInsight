#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, tmp, cnt = 0;
  cin >> N;
  
  vector<int> d(N);
  
  for(int i = 0; i < N ; i++) {
     cin >> d.at(i);
  }
  
  for(int i = 0; i < N ; i++) {
    for(int j = 0; j < N-1; j++) {
      if(d.at(j)>d.at(j+1)) {
        tmp = d.at(j);
        d.at(j) = d.at(j+1);
        d.at(j+1) = tmp;
      }
    }
  }
  for(int i = 0; i < N-1 ; i++) {
    if(d.at(i) != d.at(i+1)) {
      cnt++;
    }
  }
  cout << cnt+1 << endl;
}