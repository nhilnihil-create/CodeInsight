#include <bits/stdc++.h>
using namespace std;
  
int main() {
    int N,A;
    cin >> N >> A;
    vector<int>x(N);
    for (int i = 0; i < N; i++) {
        cin >> x.at(i);
        x.at(i) = abs(x.at(i)-A);
    }

    if (N == 1){
        cout << x.at(0) << endl;
        return 0;
    }
    
    int X = x.at(0);
    int Y = x.at(1);
    int Z = X % Y;
    int count;

    for (int i = 1; i < N; i++) {
      count = 0;
      while (count == 0){
        if (Z == 0){
          if (i != N-1){
            X = x.at(i+1);
            Z = X % Y;
          }
          count++;
        }
        else {
          X = Y;
          Y = Z;
          Z = X % Y;
        }
      }
    }
    cout << Y << endl;
}