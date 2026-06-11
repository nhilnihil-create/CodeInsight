#include<bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();
  
  int ans = 1001001001;
  for (int i= 0; i < n-2; i++) {
    int a = stoi(s.substr(i,3));
    int b = abs(a-753);
    ans = min(ans,b);
  }
  
  cout << ans << endl;
}