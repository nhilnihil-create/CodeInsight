#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i=0; i<n; i++){
    cin >> p[i];
  }

  int expensive=0;
  int total=0;
  for(int i=0; i<n; i++){
    total += p[i];
    if(expensive<p[i]) expensive = p[i];
  }

  total -= expensive/2;

  cout << total << endl;

}
