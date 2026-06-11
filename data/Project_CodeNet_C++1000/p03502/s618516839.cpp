#include <bits/stdc++.h>
using namespace std;

int main() {
  int x;
  cin>>x;
  function<int(int)> f=[&](int x) {
    int res =0;
    while (x) {
      res += (x%10);
      x/=10;
    }
    return res;
  };
    cout<<(x%f(x)==0 ? "Yes\n" : "No\n");
}
