#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  if (((n%10==((n-n%10)%100/10))&&(n%10==((n-n%100)%1000/100)))||((n/1000==((n-n%10)%100/10))&&(n/1000==((n-n%100)%1000/100)))) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}