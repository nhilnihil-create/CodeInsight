#include <bits/stdc++.h>
using namespace std;

int main(){
  int A , B;
  cin >> A >> B;
  int an = A + B;
  int sw = A - B;
  int er = A * B;
  cout << max({an , sw , er}) << endl;
}
