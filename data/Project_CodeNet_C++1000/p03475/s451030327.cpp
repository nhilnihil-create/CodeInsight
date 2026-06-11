#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;  cin >> n;
  vector<int> c(n-1), s(n-1), f(n-1);
  for(int i=0; i<n-1; i++)
    cin >> c[i] >> s[i] >> f[i];
  
  for(int j=0; j<n-1; j++){
    int nowt = 0;
    for(int i=j; i<n-1; i++){
      nowt = ((max(nowt, s[i])-1) / f[i] + 1) * f[i] + c[i];
    }
    cout << nowt << endl;
  }

  cout << "0" << endl;

  return 0;
}
