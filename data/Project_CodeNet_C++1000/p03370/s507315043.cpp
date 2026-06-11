#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, x;
  cin >> n >> x;
  int mmin = 10000000, msum = 0;
  for(int i = 0; i < n; i++){
    int m;
    cin >> m;
    msum += m;
    mmin = min(mmin, m);
  }
  cout << n + (x - msum) / mmin << endl;
}