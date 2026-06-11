#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, X;
  cin >> N >> X;
  vector<int> x(N);
  for(int i = 0; i < N; i++) cin >> x.at(i);
  vector<int> y(N);
  for(int i = 0; i < N; i++) y.at(i) = abs(X - x.at(i));
  int q;
  
  if(N == 1){
    cout << y.at(0) << endl;
  }
  else if(N == 2){
    cout << gcd(y.at(0), y.at(1)) << endl;
  }
  else{
    q = gcd(y.at(0), y.at(1));
    for(int i = 2; i < N; i++){
      q = gcd(q, y.at(i));
    }
  cout << q << endl;
  }
      
}