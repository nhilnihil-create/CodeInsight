#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int D; cin >> D;
  string S = "Christmas";
  if(D == 24){
    S += " Eve";
  } else if(D ==23){
    S += " Eve Eve";
  } else if(D == 22 ){
    S += " Eve Eve Eve";
  }
  cout << S <<endl;
}
