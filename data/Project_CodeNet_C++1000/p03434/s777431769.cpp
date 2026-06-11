#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++) {
      cin >> vec.at(i);
    }

    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());
    int Alice = 0, Bob = 0;
    for (int i = 0; i < n; i++) {
      if (i % 2 == 0) {
        Alice += vec.at(i);
      } else {
        Bob += vec.at(i);
      }
    }
    cout << Alice - Bob << endl;
  
}