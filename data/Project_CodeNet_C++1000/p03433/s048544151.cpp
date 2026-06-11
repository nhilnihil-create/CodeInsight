#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, A;
  cin >> N >> A;
  
  if (500 > N && A >= N) {
    cout << "Yes" << endl;
  }
  
  else if (N % 500 <= A) {
    cout << "Yes" << endl;
  }
  
  else {
    cout << "No" << endl;
  }
  
}