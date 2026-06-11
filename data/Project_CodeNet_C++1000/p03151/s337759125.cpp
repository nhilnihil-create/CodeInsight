#include <bits/stdc++.h>
using namespace std;

int main(){
  long long int N, norma = 0, ans = 0, ans2 = 0;
  cin >> N;
  vector<int> A(N), B(N), sabun(N);
  
  for (int i = 0; i < N; i++){
    cin >> A.at(i);
  }
  
  for (int i = 0; i < N; i++){
    cin >> B.at(i);
  }
  
  for (int i = 0; i < N; i++){
    sabun.at(i) = B.at(i) - A.at(i);
    if (B.at(i) - A.at(i) > 0){
      norma += B.at(i) - A.at(i);
      ans++;
    }
  }
  
  sort(sabun.begin(), sabun.end());
  
  while (norma > 0 && ans2 < N){
    norma += sabun.at(ans2);
    ans2++;
  }
  
  if (norma > 0){
    cout << "-1" << endl;
  }
  else{
	cout << ans + ans2 << endl;
  }
}