#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> a(n,0);
  for (int i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());

  int alice = 0;
  int bob = 0; 
  while(1){

    if (a.size() == 0) break;    
    alice += a.back();
    a.pop_back();

    if (a.size() == 0) break;
    bob += a.back();
    a.pop_back();
  }

  cout << alice - bob << endl;

}
