#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define _GLIBCXX_DEBUG

int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  rep(i, N) cin >> a[i];
  sort(a.begin(), a.end(), greater<int>());
  
  int Alice=0;
  int Bob=0;
  
  rep(i, N) {
    if (i%2==0) Alice+=a[i];
    else Bob+=a[i];
  }
  cout << Alice - Bob << endl;
}
