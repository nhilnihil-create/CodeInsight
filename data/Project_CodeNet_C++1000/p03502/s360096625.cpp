#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int fN = 0;
  
  for (int i=0; i < 9; i++) {
    fN += N % (int)pow(10, i+1) / (int)pow(10, i);
  }
  
  if (N % fN == 0) {
    cout << "Yes" << endl;
  } else {
	cout << "No" << endl;
  }
}
