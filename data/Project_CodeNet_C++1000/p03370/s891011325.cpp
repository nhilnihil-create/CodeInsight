#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;
  int sum = 0;
  int minl = 1000;
  for(int i=0; i<n; i++) {
    int m;
    cin >> m;
    sum+=m;
    minl = min(minl,m);
  }
  cout << n+(x-sum)/minl << endl;
}