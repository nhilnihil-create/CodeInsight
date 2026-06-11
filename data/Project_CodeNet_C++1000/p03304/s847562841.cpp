#include <bits/stdc++.h>
using namespace std;
int main(){
  cout << fixed << setprecision(20);
  long long n, m, d;
  cin >> n >> m >> d;
  if (d == 0){
    cout << (double) (n - d) / (n * n) * (m - 1) << endl;
  } else {
    cout << (double) (n - d) * 2 / (n * n) * (m - 1) << endl;
  }
}