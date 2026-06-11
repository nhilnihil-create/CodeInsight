#include <bits/stdc++.h>
using namespace std;
int main() {
int64_t N;
cin >> N;
for (int64_t i = N;i > 0;i--) {
  int a = sqrt(i);
  if (i == a * a) {
    cout << i << endl;
    return 0;
  }
}




return 0;
}