#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  sort(a.begin(), a.end());
  double m = (double)(a[n-1]+1)/2;
  double d = a[n-1];
  int res;
  for (int i = 0; i < n-1; i++) {
    if (abs(a[i]-m)<d) {
      res = i;
      d = abs(a[i]-m);
    }
  }

  cout << a[n-1] << " " << a[res] << endl;
  return 0;
}
