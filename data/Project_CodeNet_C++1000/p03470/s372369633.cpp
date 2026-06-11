#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  int d[n];
  for(int i = 0; i < n; ++i){
    cin >> d[i];
  }
  sort(d,d+n);
  int res = 1;
  for(int i = n-2; i >= 0; --i){
    if(d[i] < d[i+1]){
      ++res;
    }
  }
  cout << res << endl;
}