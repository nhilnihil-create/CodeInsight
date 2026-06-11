#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  vector<int> num(4,0);
  vector<int> numans = {1,1,2,2};
  for (int i=0; i<6; i++) {
    cin >> N;
    num[N-1]++;
  }
  sort(num.begin(),num.end());
  if (num == numans) {
    cout << "YES" << endl;
  }
  else {
    cout << "NO" << endl;
  }
}