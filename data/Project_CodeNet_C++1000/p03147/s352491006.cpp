#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  int N, C=0;
  cin >> N;
  vector<int> h(N);
  for (int i=0; i<N; i++) {
    cin >> h[i];
  }
  while (true) {
    int fin=1, m;
    for (int i=0; i<N; i++) {
      if (h[i]>0) {
        fin=0;
        m=i;
        break;
      }
    }
    if (fin==1) {break;}
    while (m<N && h[m]>0) {
      h[m]--;
      m++;
    }
    C++;
  }
  cout << C << endl;
}