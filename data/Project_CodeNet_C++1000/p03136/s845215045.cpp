#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N; cin >> N;
  int summ = 0;
  int x = 0, maxn = INT_MIN;
  for(int i = 0; i < N; ++i){
    cin >> x;
    summ += x;
    maxn = max(maxn,x);
  }
  cout << (summ - maxn > maxn ? "Yes" : "No") << '\n';
  return 0; 
}