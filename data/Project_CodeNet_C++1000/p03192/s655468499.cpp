#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  string N;
  cin >> N;
  int n = N.size();
  int count_2 = 0;
  rep(i,n) {
    if (N[i] == '2') {
      count_2++;
    }
  }
  cout << count_2 <<endl;


}