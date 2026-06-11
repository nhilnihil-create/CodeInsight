#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin>>n>>k;
  long long cnt = 0;
  for (int b=k+1; b<=n; b++) {
    cnt += ((n - b) / b + 1) * (b - k);
    if (k == 0) {
      --cnt;
    }
    cnt += max(n % b - k + 1, 0);
  }
  cout<<cnt<<endl;
}