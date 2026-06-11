#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> d(n);

  for(int i=0;i<n;i++) {
    cin >> d.at(i);
  }

  sort(d.begin(), d.end());
  
  int ans = d.size();
  for(int i=0;i<n-1;i++) {
    if(d.at(i) == d.at(i+1)) {
      ans--;
    }
  }

  cout << ans << endl;
}
