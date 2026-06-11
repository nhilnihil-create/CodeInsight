#include <bits/stdc++.h>
using namespace std;

int n;
int t[100010];
int x[100010];
int y[100010];

int main(){
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> t[i] >> x[i] >> y[i];
  }
  t[0] = 0;
  x[0] = 0;
  y[0] = 0;
  string res = "Yes";
  for(int i = 1; i <= n; ++i){
    if((t[i] - t[i-1]) < (abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]))){
      res = "No";
    }
    if((t[i] - t[i-1]) % 2 != (abs(x[i] - x[i-1]) + abs(y[i] - y[i-1])) % 2){
      res = "No";
    }
  }
  cout << res << endl;
}