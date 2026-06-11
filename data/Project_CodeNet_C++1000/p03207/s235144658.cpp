#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> p(n);
  int max = 0;
  for (int i=0 ; i<n ; i++)
    cin >> p.at(i);
  
  sort(p.begin(), p.end());
  
  int ans = 0;
  for (int i=0 ; i<n-1 ; i++)
    ans += p.at(i);
  ans += p.at(n-1)/2;
  
  cout << ans << endl;
}