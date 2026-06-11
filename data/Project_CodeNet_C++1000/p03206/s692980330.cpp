# include <bits/stdc++.h>
using namespace std;
int main () {
  int a;
  cin >> a;
  cout << "Christmas";
  if (a != 25) {
    int j = 25-a;
    for (int i=0; i<j; i++) {
      cout << " " << "Eve";
    }
  }
}