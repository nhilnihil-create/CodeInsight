#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int>t(N);
  vector<int>x(N);
  vector<int>y(N);
  
  for (int i = 0; i < N; i++) {
    cin >> t.at(i) >> x.at(i) >> y.at(i);
  }
  int T = 0;
  int X = 0;
  int Y = 0;
  
  for (int i = 0; i < N; i++) {
    if (t.at(i)-T < abs(x.at(i)-X) + abs(y.at(i)-Y) || (t.at(i)-T)%2 != (abs(x.at(i)-X) + abs(y.at(i)-Y))%2){
      cout << "No" << endl;
      return 0;
    }
    T = t.at(i);
    X = x.at(i);
    Y = y.at(i);
  }
  cout << "Yes" << endl;
}
      