#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  int input = 1;
  
  for (int i = 0; i < N; i++) {
    int data1 = input * 2;
    int data2 = input + K;
    if (data1 > data2) {
      input = data2;
    }
    else {
      input = data1;
    }
  }
  cout << input << endl;
}
  
