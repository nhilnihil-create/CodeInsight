#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<int> radii(N);
  for(int i = 0; i < N; i++){
    cin >> radii.at(i);
  }
  sort(radii.begin(),radii.end());
  int ans = 0;
  int last;
  for(int i = 0; i < N; i++){
    if(i == 0){
      ans += 1;
    }else{
      if(radii[i] != last){
        ans += 1;
      }
    }
    last = radii[i];
  }
  cout << ans << endl;
  return 0;
}