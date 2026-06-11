#include <bits/stdc++.h>
using namespace std;
const int INF = 1001001001;

int shift4(int n, int k){
  for(int i=0; i<k; ++i) n /= 4;
  return n%4;
}

int main(){
  int n, a, b, c;
  cin >> n >> a >> b >> c;
  vector<int> bom(n);
  for(int i=0; i<n; ++i) cin >> bom[i];
  int n4 = 1;
  for(int i=0; i<n; ++i) n4 *= 4;
  
  int ans = INF;
  for(int i=0; i<n4; ++i){
    int nans = -30;
    vector<int> abc(4,0);
    for(int j=0; j<n; ++j){
      int x = shift4(i, j);
      if(x < 3) nans += 10;
      abc[x] += bom[j];
    }
    if(abc[0] == 0 || abc[1] == 0 || abc[2] == 0) continue;
    nans += abs(abc[0] - a);
    nans += abs(abc[1] - b);
    nans += abs(abc[2] - c);
    ans = min(ans, nans);
  }
  cout << ans << endl;
}