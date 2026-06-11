#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  int N, M=0;
  cin >> N;
  vector<int> V(N);
  for (int i=0; i<N; i++) {
    cin >> V[i];
  }
  int m=1000000001, mi;
  while(true) {
    for (int i=0; i<N; i++) {
      if (V[i]==0) {continue;}
      if (m>V[i]) {
        m=V[i];
        mi=i;
      }
    }
    if (m==M) {break;}
    M=m;
    
    for (int i=0; i<N; i++) {
      if (i==mi) {continue;}
      V[i]%=m;
    }
  }
  cout << M << endl;
}