#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> in;
  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    in.push_back(tmp);
  }
  int alice = 0, bob = 0;
  sort(in.begin(), in.end());
  reverse(in.begin(), in.end());
  //for (int i = 0; i < n; i++)
    //cout << in[i] << endl;
  for (int i = 0; i < n; i++) {
    if (i % 2 == 0) {
      alice += in[i];
    }
    else {
      bob += in[i];
    }
  }
  cout << alice - bob<<endl;
}
