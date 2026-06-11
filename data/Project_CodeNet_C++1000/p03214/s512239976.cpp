#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int> a(N);
  for(int i = 0; i< N; i++) cin >> a.at(i);
  
  int ave = 0;

  for(int i = 0; i< N; i++){
    ave += a.at(i); 
  }
  
  int ans = 0;
  int minv = abs(a.at(0)*N - ave);
  for(int i = 1; i< N; i++){
    if (minv > abs(a.at(i)*N - ave)){
      minv = abs(a.at(i)*N - ave);
      ans = i;
    }
  }
  
  cout << ans << endl;
}