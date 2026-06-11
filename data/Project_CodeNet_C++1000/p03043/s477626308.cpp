#include <bits/stdc++.h>
using namespace std;
using pp=pair<int,int>;
using ll=long long;

int main() {
  int N, K;
  double m, S=0;
  cin >> N >> K;
  for (int i=1; i<=N; i++) {
    int j=0;
    while (true) {
      if (i*pow(2,j)>=K) {
        m=pow(2,j);
        break;
      }
      j++;
    }
    S+=1/m;
  }
  cout << fixed << setprecision(15) << S/(double)N << endl;
}