#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,A;
  int minr = 1000000000;
  int tmp = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A;
    while (A%2 == 0){
    tmp++;
    A/=2;
    }
    if (minr > tmp){
      minr = tmp;
    }
    tmp = 0;
  }
 cout << minr << endl;
}