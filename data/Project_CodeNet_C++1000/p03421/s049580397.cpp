#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b;
  cin>>n>>a>>b;
  if (a > n - b + 1) {
    cout<<-1<<endl;
    return 0;
  }
  if (a > 1 && (n - b - 1) / (a - 1) + 1 > b) {
    cout<<-1<<endl;
    return 0;
  }
  vector<int> v;
  for (int i=b; i>0; --i) {
    v.push_back(i);
  }
  int used = b;
  for (int i=1; i<a; i++) {
    int len = (n - used - 1) / (a - i) + 1;
    for (int j=len; j>0; j--) {
      v.push_back(used+j);
    }
    used += len;
  }
  for (int i=0; i<n; i++) {
    cout<<v[i];
    if (i != n - 1) {
      cout<<" ";
    }
  }
  cout<<endl;
}