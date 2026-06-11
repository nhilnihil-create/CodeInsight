#include <bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}
int main() {
  int n;
  cin>>n;
  if (n == 3) {
    cout<<"2 5 63"<<endl;
    return 0;
  }
  vector<int> ans;
  int rest = n;
  int a = 3;
  while (rest - 2 >= 2 && a + 6 <= 30000) {
    ans.push_back(a);
    ans.push_back(a + 6);
    a += 12;
    rest -= 2;
  }
  int b = 2;
  while (rest > 2) {
    ans.push_back(b);
    ans.push_back(b + 2);
    ans.push_back(b + 4);
    b += 6;
    rest -= 3;
  }
  if (rest == 2) {
    ans.push_back(b);
    ans.push_back(b + 2);
  } else if (rest == 1) {
    ans.push_back(b + 4);
  }

  for (int i=0; i<n; i++) {
    cout<<ans[i];
    if (i != n - 1) {
      cout<<" ";
    }
  }
  cout<<endl;
}