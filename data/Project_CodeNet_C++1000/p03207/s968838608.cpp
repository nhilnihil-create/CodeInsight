#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;

  int expensive=0;
  int total=0;
  for(int i=0; i<n; i++){
    int p;
    cin >> p;
    total += p;
    if(expensive<p) expensive = p;
  }

  total -= expensive/2;

  cout << total << endl;

}
