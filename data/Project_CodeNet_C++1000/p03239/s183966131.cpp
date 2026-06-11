#include<bits/stdc++.h>
using namespace std;

int main (void){
  int n = 0,t = 0, min = 10000;

  cin >> n >> t;

  vector<int> c(n,0);
  vector<int> h(n,0);

  for(int i = 0;i < n;i++){
    cin >> c[i];
    cin >> h[i];
  }

  for(int i = 0;i < n;i++){
    if(h[i] <= t){
      if(min > c[i]){
        min = c[i];
      }
    }
  }
  if(min <= 1000){
    cout << min << endl;
  }else{
    cout << "TLE\n";
  }

  return 0;
}