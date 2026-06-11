#include<bits/stdc++.h>
using namespace std;
int main() {
  int n, x; cin >> n >> x;
  vector<int> a(n);
  for(int &c : a) {
    cin >> c;
  }
  sort(a.begin(), a.end());
  long long sum = 0;
  for(int c : a) {
    sum += c;
  }
  if(sum < x) {
    cout << n -1 << endl;
  }
  else if(sum == x) {
    cout << n << endl;
  }
  else {
    int given = 0, count = 0;
    while(given < x) {
      given += a.at(count);
      count++;
    }
    if(given == x) {
      cout << count << endl;
    }
    else {
      cout << count -1 << endl;
    }
  }
}