#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<long long>a(n);
  vector<long long>b(n);
  vector<long long>d(n);

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  for (int i = 0; i < n; i++) {
    d[i] = a[i]-b[i];
  }
  sort(d.begin(),d.end());
  long long hiku=0,num1,num2;
  for (int i = 0; i < n; i++) {
    if (d[i] < 0) {
      hiku += d[i];
    }
    else {
      num1 = i;
      break;
    }
  }

  if (hiku == 0) {
    cout << 0 << endl;
    return 0;
  }

  for (int i = n-1; i >= 0; i--) {
    hiku += d[i];
    if (hiku >= 0) {
      num2 = i;
      break;
    }
  }
  if (hiku < 0) {
    cout << -1 << endl;
    return 0;
  }
  cout << n-(num2-num1) << endl;
}  
