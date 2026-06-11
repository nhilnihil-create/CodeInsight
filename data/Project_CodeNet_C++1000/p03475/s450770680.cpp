#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  vector<int> c(n-1), s(n-1), f(n-1);
  for(int i = 0; i < n-1; i++) cin >> c[i] >> s[i] >> f[i];
  for(int i = 0; i < n-1; i++){
    int time = 0;
    for(int j = i; j < n-1; j++){
      if(time < s[j]) time = s[j];
      else if(time % f[j]) time = time + f[j] - time%f[j];
      time += c[j];
    }
    cout << time << endl;
  }
  cout << 0 << endl;
}