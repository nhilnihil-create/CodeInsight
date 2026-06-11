#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  double count = 0;//yen
  
  for (int i = 0;i < N;i++) {
    double x;
    string u;
    cin >> x >> u;
    if (u == "BTC") {
      x = x * 380000.0;
    }
    count += x;
  }
  
  cout << count << endl;
}
