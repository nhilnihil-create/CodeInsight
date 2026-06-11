#include <bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  string s;
  cin >> s;
  int sum = 0;
  for(int i=1; i<n; ++i) if(s[i] == 'E') ++sum;
  int ans = sum;
  for(int i=1; i<n; ++i){
    int tmp = 0;
    if(s[i-1] == 'W') ++tmp; 
    if(s[i] == 'E') --tmp;
    sum += tmp;
    ans = min(ans, sum); 
  }
  cout << ans << endl;
}