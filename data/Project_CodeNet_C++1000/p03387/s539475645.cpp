#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> x(3);
  for (int i = 0; i < 3; i++) {
    cin >> x[i];
  }
  int &a = x[0];
  int &b = x[1];
  int &c = x[2];
  sort(x.begin(), x.end());
  int count = 0;
  if (c > b) {
    for (int i = 0; i < 50; i++) {
      a++;
      b++;
      count++;
      if(c==b) {
        break;
      }
    }
  }
  
  //ここからA
  if ((b-a)%2==0) {
    count+=(b-a)/2;
  }
  else {
    count+=(b-a)/2+1+1;
  }
  cout << count << endl;
}
