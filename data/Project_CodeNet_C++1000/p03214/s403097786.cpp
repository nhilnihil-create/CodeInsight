#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#define rep(i,n) for (int i=0; i<n; i++)
#include<math.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> a(N);
  for (int i=0; i<N; i++) {
    cin >> a[i];
  }
  int sum = 0;
  for (int i=0; i<N; i++) {
    sum += a[i];
  }
  int mi = 100000;
  int mi1;
  for (int i=0; i<N; i++) {
    a[i] *= N;
    if (mi > abs(a[i]-sum)) {
      mi = abs(a[i]-sum);
      mi1 = i;
    }
  }
  cout << mi1 << endl;
}