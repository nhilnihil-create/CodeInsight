#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using p = pair<int, int>;
typedef vector<int> vi;

int findSumOfDigits(int n) {
  int sum = 0;
  while(n > 0) {
    sum += n % 10;
    n /= 10;
  }
  return sum;
}

int main() {
  int N;
  cin >> N;

  if (N % findSumOfDigits(N) == 0) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}