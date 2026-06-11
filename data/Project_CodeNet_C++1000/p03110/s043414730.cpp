#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  double x, S=0;
  string u;
  cin >> N;
  for (int i=0; i<N; i++) {
    cin >> x >> u;
    if (u=="BTC") {
      S+=x*380000;
    }
    else {
      S+=x;
    }
  }
  cout << S << endl;
}

