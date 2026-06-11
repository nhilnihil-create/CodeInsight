#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> num(3);
  for(int i =0; i < 3;i++){
    cin >> num.at(i);
  }
  sort(num.begin(), num.end());
  int d = num.at(0), e = num.at(1), f = num.at(2);
  int ans = 0;
  if((e-d)%2 == 1){
    d++;
    f++;
    ans++;
  }
  ans += (e-d)/2 + (f-e);
  cout << ans << endl;
}

