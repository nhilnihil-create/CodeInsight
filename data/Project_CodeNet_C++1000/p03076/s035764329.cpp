#include <bits/stdc++.h>
using namespace std;

int main() {
  int sum = 0;
  int ans = 100000;
  vector<int> vec(5);
  for(int i=0;i<5;++i){
    cin >> vec.at(i);
  }

  for(int i=0;i<5;++i){
    for(int j=0;j<4;++j){
      sum += vec.at(j);
      if(sum % 10 != 0){
        sum += 10 - vec.at(j)%10;
      }
    }
    sum += vec.at(4);
    if(ans > sum) ans = sum;
    sum = 0;
    vec.push_back(vec.at(0));
    vec.erase(vec.begin());
  }
  cout << ans << endl;
  return 0;
}
