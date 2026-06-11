#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int>hight(N);
  
  for(int i=0; i<N; i++)cin >> hight.at(i);
  
  sort(hight.begin(), hight.end());
  
  int ans = 2000000000;
  
  for(int i=0; i<N-K+1; i++){
    ans = min(ans, hight.at(i+K-1)-hight.at(i));
  }
  
  cout << ans << endl;
}