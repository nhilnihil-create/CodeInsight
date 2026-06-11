#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  
  vector<double>x(N);
  vector<string>u(N);
  for (int i = 0; i < N; i++) {
    cin >> x.at(i) >> u.at(i);
  }

  double sum = 0;
  for (int i = 0; i < N; i++) {
    if (u.at(i) == "JPY"){
      sum += x.at(i);
    }
    else {
      sum += x.at(i)*380000.0;
    }
  }
  printf("%.8lf\n", sum);
}
  

