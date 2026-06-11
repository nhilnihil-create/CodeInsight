#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int>A1(N);
  vector<int>A2(N);
  
  for(int i=0; i<N; i++)cin >> A1.at(i);
  for(int i=0; i<N; i++)cin >> A2.at(i);
  
  int count =0;
  int ans =0;
  
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      if(j<i)count += A1.at(j);
      else if (j==i) count += A1.at(j)+A2.at(j);
      else count += A2.at(j);
    }
    ans = max(ans, count);
    count =0;
  }
  
  cout << ans << endl;
}
