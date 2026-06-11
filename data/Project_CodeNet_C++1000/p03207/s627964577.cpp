#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int n;
  cin >> n;
  vector<int> p(n);
  for(int i=0; i<n; i++){
    cin >> p[i];
  }

  sort(p.begin(), p.end());

  int total=0;
  for(int i=0; i<n; i++){
    if(i==n-1) total += p[i] / 2;
    else total += p[i];
  }

  cout << total << endl;
}
