#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;
  double T, A;
  cin >> N >> T >> A;


  vector<double> H(N);
  for (int i = 0; i < N; i++)
  {
    cin >> H.at(i);
  }
  
  int near = 0;
  double tmp;

  for (int i = 0; i < N; i++)
  {
    tmp = T - H.at(i) * 0.006;
    if (abs(A - tmp) < abs(A - (T - H.at(near) * 0.006))){
      near = i;
    } 
  }
  cout << near + 1 << endl;
}