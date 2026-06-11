#include <bits/stdc++.h>
using namespace std;

int main() {
  int k;
  cin>>k;
  long long a[k];
  for (int i=0; i<k; i++) cin>>a[i];

  if (a[k-1] != 2) {
    cout<<-1<<endl;
    return 0;
  }
  long long max_n = 3, min_n = 2;;
  for (int i=k-2; i>=0; i--) {
    min_n = max(a[i], min_n);
    min_n = a[i] * ((min_n - 1) / a[i] + 1);
    long long max_n_group = max_n / a[i];
    if (max_n_group == 0) {
      cout<<-1<<endl;
      return 0;
    }
    if (max_n_group * a[i] + a[i] - 1 < max_n) {
      cout<<-1<<endl;
      return 0;
    }
    max_n = max_n_group * a[i] + a[i] - 1;
  }
  long long x = max_n, y = min_n;
  for (int i=0; i<k; i++) {
    x = x / a[i] * a[i];
    y = y / a[i] * a[i];
  }
  if (x != 2 || y != 2) {
    cout<<-1<<endl;
  } else {
    cout<<min_n<<" "<<max_n<<endl;
  }
}