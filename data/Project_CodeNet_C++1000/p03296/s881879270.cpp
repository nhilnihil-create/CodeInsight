#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[]) {
  int n, flag = 0;
  cin  >> n;
  vector <int> a(n, 0);
  for(int i = 0;i < n;i++) {
    cin >> a.at(i);
    if(i != 0) {
      if(a.at(i-1) == a.at(i)) {
        a.at(i) += 100;
        flag++;
      }
    }
  }
  cout << flag << endl;
  return 0;
}
