#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  long double P=0;
  cin >> N;
  vector<double>K(N);
  vector<string>H(N);
  for(int i = 0;i < N;i++){
    cin >> K[i];
    cin >> H[i];
  }
  for(int i = 0;i < N;i++){
    if(H[i] == "JPY") P += K[i];
    else P += (380000 * K[i]);
  }
  cout << P <<endl;
}