#include<bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  string str = to_string(N);
  
  int digitSum = 0;
  for (char c : str) {
    digitSum += c - '0';
  }
  if (N % digitSum == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}
